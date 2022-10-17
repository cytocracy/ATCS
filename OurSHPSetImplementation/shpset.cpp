//
// Created by Theo on 10/17/2022.
//

#include "shpset.h"

shpset::shpset() {
    root = nullptr;
}

shpset::~shpset() {

}

void shpset::insert(string value) {

}

void shpset::erase(string value) {

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
    return containsHelper(value, tree->left) || containsHelper(value, tree->right);
}

void shpset::clear() {

}

vector<string> shpset::getVector() const {
    return vector<string>();
}

