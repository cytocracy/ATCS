//
// Created by Theo on 10/17/2022.
//

#ifndef OURSHPSETIMPLEMENTATION_SHPSET_H
#define OURSHPSETIMPLEMENTATION_SHPSET_H

#include <iostream>
#include <vector>

using namespace std;

class shpset{
public:
    shpset();
    ~shpset();

    void insert(string value);
    void erase(string value);
    int size() const;
    bool contains(string value) const;
    void clear();
    vector<string> getVector() const;

private:
    struct TreeNode {
        string value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(){
            left = nullptr;
            right = nullptr;
        }
    };
    TreeNode* root;

    //recursive helper functions
    int sizeHelper(TreeNode* tree) const;
    bool containsHelper(string value, TreeNode* tree) const;
    void clearHelper(TreeNode* &tree);
    void insertHelper(string value, TreeNode* &tree);
    void getVectorHelper(TreeNode* tree, vector<string> &vec) const;
    TreeNode* eraseHelper(string value, TreeNode* &tree);
    TreeNode* getMaxValueNode(TreeNode* tree) const;
};


#endif //OURSHPSETIMPLEMENTATION_SHPSET_H
