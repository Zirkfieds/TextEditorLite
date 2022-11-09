#ifndef AVLTREE_H
#define AVLTREE_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

#define DEFAULTFREQ 0

typedef class stringKey {
public:
    string str;

    stringKey() {
        str = "";
        return;
    }

    stringKey(string& s) {
        str = s;
        return;
    }

    bool operator==(stringKey const& r) {
        return this->str.compare(r.str) == 0 ? true : false;
    }

    bool operator>(stringKey const& r) {
        return this->str > r.str;
    }

    bool operator<(stringKey const& r) {
        return this->str < r.str;
    }

} skey;

class AVLTNode {
public:
    skey data;
    int freq;

    AVLTNode* lc, * rc;

    AVLTNode(string& s, int c) {
        data.str = s;
        freq = c;
        lc = rc = nullptr;
        return;
    }

    AVLTNode(skey const& k) {
        data = k;
        freq = DEFAULTFREQ;
        lc = rc = nullptr;
        return;
    }

    AVLTNode(skey& k) {
        data = k;
        freq = DEFAULTFREQ;
        lc = rc = nullptr;
        return;
    }

    AVLTNode() {
        data.str = "";
        freq = DEFAULTFREQ;
        lc = rc = nullptr;
        return;
    }
};

class AVLTree {
private:
    AVLTNode* root;

    void rotateLL(AVLTNode*&);
    void rotateRR(AVLTNode*&);
    void rotateRL(AVLTNode*&);
    void rotateLR(AVLTNode*&);

public:

    AVLTree();

    AVLTNode* locateNode(skey const&);

    void insert(skey const&, bool);
    void insertNode(AVLTNode*&, skey const&, bool);

    void delTrav(AVLTNode*);
    void deleteTree();

    void travTrackFreq(AVLTNode*, vector<double>&);
    void travTrackFreqFromRoot(vector<double>&);

    int getHeight(AVLTNode*);

    ~AVLTree();

};
#endif // AVLTREE_H
