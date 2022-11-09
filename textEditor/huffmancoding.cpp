#include "huffmancoding.h"

huffmanCoding::huffmanCoding(string& str) {

    this->str = str;
    root = nullptr;
    for (int i = 0; i < FULLASCIISIZE; i++) {
        pair<char, int> p;
        p.first = char(i);
        p.second = 0;
        charFreq.push_back(p);
    }
    codable = true;
    leafCnt = 0;
    getCharFreq();

    return;
}

huffmanCoding::huffmanCoding() {

    root = nullptr;
    for (int i = 0; i < FULLASCIISIZE; i++) {
        pair<char, int> p;
        p.first = char(i);
        p.second = 0;
        charFreq.push_back(p);
    }
    leafCnt = 0;
    codable = true;

    return;
}

void huffmanCoding::getCharFreq() {

    charFreq.clear();
    leafCnt = 0;
    for (int i = 0; i < FULLASCIISIZE; i++) {
        pair<char, int> p;
        p.first = char(i);
        p.second = 0;
        charFreq.push_back(p);
    }

    for (auto c : str) {
        if (int(c) < FULLASCIISIZE) charFreq[c].second++;
    }

    sort(charFreq.begin(), charFreq.end(), desc);

    for (auto p = charFreq.begin(); p != charFreq.end(); p++) {
        if (p->second == 0) {
            notZero = p;
            break;
        }
        leafCnt++;
    }
    nodeCnt = leafCnt * 2 - 1;

    root = new HTreeNode[nodeCnt + 1];
    auto* tmp = root;
    int i = 0;
    root[0].weight = 0;

    tmp++;
    for (i = 1; i <= leafCnt; i++, tmp++) {
        tmp->weight = charFreq[i - 1].second;
        tmp->lchild = tmp->rchild = tmp->parent = NOTCONNECTED;
    }
    for (; i <= nodeCnt; i++, tmp++) {
        tmp->weight = 0;
        tmp->lchild = tmp->rchild = tmp->parent = NOTCONNECTED;
    }

    return;
}

pair<int, int> huffmanCoding::getMinimumWeightPair(int n) {

    int min, secmin;
    secmin = min = MINIMUM;

    int minIndex = 1, secminIndex = 1;
    for (int i = 1; i <= n; i++) {
        if (root[i].weight < min && root[i].parent == NOTCONNECTED) {
            min = root[i].weight;
            minIndex = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((root[i].weight < secmin) && (i != minIndex) && root[i].parent == NOTCONNECTED) {
            secmin = root[i].weight;
            secminIndex = i;
        }
    }

    return make_pair(minIndex, secminIndex);
}

void huffmanCoding::createHTree() {

    for (int i = leafCnt + 1; i <= nodeCnt; i++)
    {
        int s1, s2;
        auto minPair = getMinimumWeightPair(i - 1);
        s1 = minPair.first;
        s2 = minPair.second;
        root[s1].parent = i;
        root[s2].parent = i;
        root[i].lchild = s1;
        root[i].rchild = s2;
        root[i].weight = root[s1].weight + root[s2].weight;
    }

    return;
}

void huffmanCoding::hEncode() {

    codedStr.clear();
    decodedStr.clear();

    for (int i = 1; i <= leafCnt; i++) {
        string hCodeStr = "";
        stack<char> ctmp;
        for (int cur = i, par = root[cur].parent;
            par != 0;
            cur = par, par = root[par].parent) {
            if (root[par].lchild == cur) {
                ctmp.push('0');
            }
            else {
                ctmp.push('1');
            }
        }
        while (!ctmp.empty()) { hCodeStr += ctmp.top(); ctmp.pop(); }
        huffmanCode.push_back(hCodeStr);
    }

    for (auto& c : str) {
        for (int i = 0; i < leafCnt; i++) {
            if (c == charFreq[i].first) {
                codedStr += huffmanCode[i];
                continue;
            }
        }
    }

    return;
}

void huffmanCoding::hDecode(string& codedStr) {

    int i = 0, j = 0;
    decodedStr.clear();
    while (j < codedStr.length()) {
        i = 2 * leafCnt - 1;
        while (root[i].lchild != NOTCONNECTED && root[i].rchild != NOTCONNECTED) {
            if (codedStr[j] == '0') {
                i = root[i].lchild;
            }
            else if (codedStr[j] == '1') {
                i = root[i].rchild;
            }
            j++;
        }
        decodedStr += charFreq[i - 1].first;
    }

    return;
}

void huffmanCoding::setHCFileInfo(string& fpath) {

    this->hcFilePath = fpath;

    return;
}

string huffmanCoding::getHCFileInfo() {

    return this->hcFilePath;
}

void huffmanCoding::generateHCFile() {

    ofstream dst(hcFilePath);
    dst << leafCnt << '\n';

    for (int i = 0; i < leafCnt; i++) {
        char ch;
        if (charFreq[i].first == ' ') {
            ch = -1;
        }
        else if (charFreq[i].first == '\n') {
            ch = -2;
        }
        else if (charFreq[i].first == '\t') {
            ch = -3;
        }
        else {
            ch = charFreq[i].first;
        }
        dst << ch << ' ' << charFreq[i].second << ' ' << huffmanCode[i] << '\n';
    }
    dst << '\n' << codedStr << '\n';

    dst.close();

    return;
}

void huffmanCoding::loadHCFile() {

    ifstream src(hcFilePath);
    src >> leafCnt;

    charFreq.clear();
    huffmanCode.clear();

    string fabricatedStr;
    for (int i = 0; i < leafCnt; i++) {
        char c; src >> c;
        char ch;
        if (c == -1) {
            ch = ' ';
        }
        else if (c == -2) {
            ch = '\n';
        }
        else if (c == -3) {
            ch = '\t';
        }
        else {
            ch = c;
        }
        int w; src >> w;

        charFreq.push_back(make_pair(ch, w));

        string hcode; src >> hcode;

        huffmanCode.push_back(hcode);
    }

    src >> this->codedStr;

    src.close();

    nodeCnt = leafCnt * 2 - 1;

    root = new HTreeNode[nodeCnt + 1];
    auto* tmp = root;
    int i = 0;
    root[0].weight = 0;

    tmp++;
    for (i = 1; i <= leafCnt; i++, tmp++) {
        tmp->weight = charFreq[i - 1].second;
        tmp->lchild = tmp->rchild = tmp->parent = NOTCONNECTED;
    }
    for (; i <= nodeCnt; i++, tmp++) {
        tmp->weight = 0;
        tmp->lchild = tmp->rchild = tmp->parent = NOTCONNECTED;
    }

    createHTree();

    return;
}

void huffmanCoding::flushPreviousData(){

    str.clear(); codedStr.clear(); decodedStr.clear();
    huffmanCode.clear();

    leafCnt = 0, nodeCnt = 0;
    delete[] root;
    root = nullptr;
    codable = true;

    return;
}

huffmanCoding::~huffmanCoding() {
    delete[] root;
}

bool desc(pair<char, int> p1, pair<char, int> p2) {

    if (p1.second == p2.second) {

        return p1.first > p2.first;
    }
    else {

        return p1.second > p2.second;
    }
}

bool asc(pair<char, int> p1, pair<char, int> p2) {

    if (p1.second == p2.second) {

        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}
