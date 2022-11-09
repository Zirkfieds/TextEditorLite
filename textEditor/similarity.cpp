#include"similarity.h"

similarity::similarity() {

    this->src = "", this->str = "";
    this->full = "";
    similarityResult = 0.0;

    return;
}

similarity::similarity(string& src, string& str) {

    this->src = src, this->str = str;
    this->full.append(src + ' ' + str);
    similarityResult = 0.0;

    return;
}

void similarity::setContent(string& src, string& str) {

    this->src = src, this->str = str;
    this->full.append(src + ' ' + str);

    return;
}

void similarity::sliceStrings() {

    istringstream issrc(src);
    while (!issrc.eof()) {
        string s; issrc >> s;
        srcSliced.push_back(s);
    }

    istringstream isstr(str);
    while (!isstr.eof()) {
        string s; isstr >> s;
        strSliced.push_back(s);
    }

    istringstream isfull(full);
    while (!isfull.eof()) {
        string s; isfull >> s;
        fullSliced.push_back(s);
    }

    for (auto s : fullSliced) {
        stringKey elem(s);
        srcContent.insert(elem, false);
        strContent.insert(elem, false);

    }

    return;
}

void similarity::initAVLTree() {

    for (auto s : srcSliced) {
        stringKey elem(s);
        srcContent.insert(elem, true);
    }

    for (auto s : strSliced) {
        stringKey elem(s);
        strContent.insert(elem, true);
    }

   return;
}

void similarity::getSimilarity(int method) {

    srcContent.travTrackFreqFromRoot(this->srcVectors);
    strContent.travTrackFreqFromRoot(this->strVectors);

    double wordCnt = (srcVectors.size() == strVectors.size()) ? (srcVectors.size()) : max(srcVectors.size(), strVectors.size());

    if (method == DISTANCE) {
        double modDiff, modSrcPow, modStrPow;

        modDiff = modSrcPow = modStrPow = 0.0;
        for (int i = 0; i < wordCnt; i++) {
            modDiff += (srcVectors[i] - strVectors[i]) * (srcVectors[i] - strVectors[i]);
            modSrcPow += (srcVectors[i]) * (srcVectors[i]);
            modStrPow += (strVectors[i]) * (strVectors[i]);
        }

        this->similarityResult = sqrt(modDiff) / sqrt((modSrcPow) * (modStrPow));

        return;
    }
    else if (method == COSINE) {
        double multVect, modSrcPow, modStrPow;

        multVect = modSrcPow = modStrPow = 0.0;
        for (int i = 0; i < wordCnt; i++) {
            multVect += (srcVectors[i] * strVectors[i]);
            modSrcPow += (srcVectors[i]) * (srcVectors[i]);
            modStrPow += (strVectors[i]) * (strVectors[i]);
        }

        this->similarityResult = multVect / (sqrt(modSrcPow) * sqrt(modStrPow));

        return;
    }
}

double similarity::getSimResult() {

    return this->similarityResult;
}
