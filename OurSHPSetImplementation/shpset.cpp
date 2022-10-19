//
// Created by Theo on 10/17/2022.
//

#include "shpset.h"

shpset::shpset() {
    root = nullptr;
}

shpset::~shpset() {
    clear();
}

void shpset::insert(string value) {
    insertHelper(value, root);
}

void shpset::insertHelper(string value, shpset::TreeNode *&tree) {
    if(tree == nullptr){
        tree = new TreeNode;
        tree->value = value;
    }
    else if(value < tree->value) insertHelper(value, tree->left);
    else if(value > tree->value) insertHelper(value, tree->right);
}

void shpset::erase(string value) {
    root = eraseHelper(value, root);
}

shpset::TreeNode *shpset::eraseHelper(string value, shpset::TreeNode *&tree) {
    if(tree == nullptr) return nullptr;
    else if(value < tree->value) tree->left = eraseHelper(value, tree->left);
    else if(value > tree->value) tree->right = eraseHelper(value, tree->right);
    else {
        if(tree->left == nullptr){
            TreeNode* save = tree->right;
            delete tree;
            return save;
        } else if (tree->right == nullptr) {
            TreeNode *save = tree->left;
            delete tree;
            return save;
        } else {
            TreeNode* temp = getMaxValueNode(tree->left);
            tree->value = temp->value;
            tree->left = eraseHelper(temp->value, tree->left);
        }
    }
    return tree;
}

shpset::TreeNode *shpset::getMaxValueNode(shpset::TreeNode *tree) const {
    if (tree == nullptr) return nullptr;
    TreeNode* temp = tree;
    while(temp->right != nullptr) temp = temp->right;
    return temp;
}

int shpset::size() const {
    return sizeHelper(root);
}

int shpset::sizeHelper(shpset::TreeNode *tree) const {
    if(tree == nullptr) return 0;
    else return 1 + sizeHelper(tree->left) + sizeHelper(tree->right);
}

bool shpset::contains(string value) const {
    return containsHelper(value, root);
}

bool shpset::containsHelper(string value, shpset::TreeNode *tree) const {
    if(tree == nullptr) return false;
    else if(value == tree->value) return true;
    else if (tree->value > value) return containsHelper(value, tree->left);
    else return containsHelper(value, tree->right);
}

void shpset::clear() {
    clearHelper(root);
}

void shpset::clearHelper(shpset::TreeNode *&tree) {
    if(tree == nullptr) return;
    clearHelper(tree->left);
    clearHelper(tree->right);
    delete tree;
    tree = nullptr;
}

vector<string> shpset::getVector() const {
    vector<string> result;
    getVectorHelper(root, result);
    return result;
}

void shpset::getVectorHelper(shpset::TreeNode *tree, vector<string> &vec) const {
    if(tree == nullptr) return;
    getVectorHelper(tree->left, vec);
    vec.push_back(tree->value);
    getVectorHelper(tree->right, vec);
}

