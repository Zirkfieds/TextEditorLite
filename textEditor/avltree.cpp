#include "avltree.h"

void AVLTree::rotateLL(AVLTNode*& root) {
    if (root) {
        AVLTNode* tmp = root->lc;
        root->lc = tmp->rc;
        tmp->rc = root;
        root = tmp;
    }
    return;
}

void AVLTree::rotateRR(AVLTNode*& root) {
    if (root) {
        AVLTNode* tmp = root->rc;
        root->rc = tmp->lc;
        tmp->lc = root;
        root = tmp;
    }
    return;
}

void AVLTree::rotateRL(AVLTNode*& root) {
    rotateLL(root->rc);
    rotateRR(root);
    return;
}

void AVLTree::rotateLR(AVLTNode*& root) {
    rotateRR(root->lc);
    rotateLL(root);
    return;
}



AVLTree::AVLTree() {
    root = nullptr;
    return;
}

AVLTNode* AVLTree::locateNode(skey const& key) {
    AVLTNode* tmp = this->root;
    while (tmp) {
        if (tmp->data == key) {
            return tmp;
        }
        else if (tmp->data > key) {
            tmp = tmp->lc;
        }
        else if (tmp->data < key) {
            tmp = tmp->rc;
        }
    }
    cerr << "NODE NOT FOUND" << endl;
    return nullptr;
}

void AVLTree::insert(skey const& key, bool incre = false) {
    insertNode(root, key, incre);
}

void AVLTree::insertNode(AVLTNode*& root, skey const& key, bool incre = false) {
    if (!root) {
        root = new AVLTNode(key);
    }
    else {
        if (root->data > key) {
            insertNode(root->lc, key, incre);
            int lh = getHeight(root->lc); int rh = getHeight(root->rc);
            if (lh - rh > 1) {
                if (root->lc->data > key) {
                    rotateLL(root);
                }
                else {
                    rotateLR(root);
                }
            }
        }
        else if (root->data < key) {
            insertNode(root->rc, key, incre);
            int lh = getHeight(root->lc); int rh = getHeight(root->rc);
            if (rh - lh > 1) {
                if (root->rc->data < key) {
                    rotateRR(root);
                }
                else {
                    rotateRL(root);
                }
            }
        }
        else if (root->data == key) {
            if (incre) {
                root->freq++;
            }
            return;
        }
        else {
            return;
        }
    }

}

void AVLTree::delTrav(AVLTNode* root) {
    if (!root) {
        return;
    }
    else {
        delTrav(root->lc);
        delTrav(root->rc);
        delete root;
    }
}

void AVLTree::deleteTree() {
    delTrav(this->root);
}

void AVLTree::travTrackFreq(AVLTNode* root, vector<double>& freqVectors) {
    if (!root) {
        return;
    }
    else {
        freqVectors.push_back(double(root->freq));

        if (root->lc || root->rc) {
            travTrackFreq(root->lc, freqVectors);
            travTrackFreq(root->rc, freqVectors);
        }
    }
}

void AVLTree::travTrackFreqFromRoot(vector<double>& freqVectors) {
    travTrackFreq(this->root, freqVectors);
}

int AVLTree::getHeight(AVLTNode* node) {
    if (node) {
        int lh = getHeight(node->lc); int rh = getHeight(node->rc);
        return lh > rh ? ++lh : ++rh;
    }
    else {
        return 0;
    }
}

AVLTree::~AVLTree() {
    deleteTree();
}
