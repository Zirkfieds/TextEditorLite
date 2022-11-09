#ifndef SIMILARITY_H
#define SIMILARITY_H

#include"avltree.h"

#include<cmath>

using namespace std;

class similarity {
private:

    AVLTree srcContent, strContent;

    string src, str;
    vector<string> srcSliced, strSliced;

    string full;
    vector<string> fullSliced;

    vector<double> srcVectors, strVectors;

    double similarityResult;

public:

    enum similarityMethodsList {
        NONE = 0, DISTANCE, COSINE
    };

    similarity();
    similarity(string&, string&);

    void setContent(string&, string&);

    void sliceStrings();
    void initAVLTree();

    void getSimilarity(int);

    double getSimResult();

};




#endif // SIMILARITY_H
