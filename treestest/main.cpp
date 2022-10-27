#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* makeTestTree() {
    //create example binary search tree of ints
    TreeNode *root = new TreeNode();
    root->value = 5;
    root->left = new TreeNode();
    root->left->value = 3;
    root->left->left = new TreeNode();
    root->left->left->value = 2;
    root->left->right = new TreeNode();
    root->left->right->value = 4;
    root->right = new TreeNode();
    root->right->value = 7;
    root->right->left = new TreeNode();
    root->right->left->value = 6;
    root->right->right = new TreeNode();
    root->right->right->value = 8;
    return root;
}

int main() {
    cout << "Hello, World!" << endl;
    TreeNode *root = makeTestTree();
    return 0;
}
