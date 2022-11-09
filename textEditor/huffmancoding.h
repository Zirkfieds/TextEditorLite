#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H

#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<stack>
#include<fstream>
#include<sstream>
using namespace std;

#define MINIMUM 0xFFFF
#define NULLCHR '^'
#define ASCIISPACE 32
#define ASCIIMAX 127
#define FULLASCIISIZE 128
#define NOTCONNECTED 0

bool desc(pair<char, int>, pair<char, int>);
bool asc(pair<char, int>, pair<char, int>);

class HTreeNode {
public:
    int weight;
    int parent, lchild, rchild;

    HTreeNode() {
        int weight = 0;
        parent = lchild = rchild = NOTCONNECTED;
    }

    HTreeNode(char elem, int weight) {
        this->weight = weight;
        parent = lchild = rchild = -1;
    }

};

class huffmanCoding {
private:
    HTreeNode* root;

    vector<pair<char, int>> charFreq;
    vector<pair<char, int>>::iterator notZero;

    vector<string> huffmanCode; //stores the huffman codes

    int leafCnt, nodeCnt;

    string str, codedStr, decodedStr;
    string hcFilePath;

    bool codable;

public:
    huffmanCoding(string&);
    huffmanCoding();

    void clearStr() { str.clear(); }

    string getContentStr() { return str; }
    void setContentStr(string& s) { this->str = s; }

    string getCodedStr() { return codedStr; }
    void clearCodedStr() { codedStr.clear(); }

    string getDecodedStr() { return decodedStr; }
    void clearDecodedStr() { decodedStr.clear(); }
    void getCharFreq();

    pair<int, int> getMinimumWeightPair(int);

    void createHTree();

    void hEncode();
    void hDecode(string&);

    void setHCFileInfo(string&);
    string getHCFileInfo();

    bool getHCodeStatus() { return !huffmanCode.empty(); }

    void updateCodableStatus(bool status) { codable = status; return; }
    bool getCodableStatus() { return codable; }

    void generateHCFile();
    void loadHCFile();

    void flushPreviousData();

    ~huffmanCoding();
};

bool desc(pair<char, int> p1, pair<char, int> p2);
bool asc(pair<char, int> p1, pair<char, int> p2);

#endif // HUFFMANCODING_H
