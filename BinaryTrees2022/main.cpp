#include <iostream>
using namespace std;

struct TreeNode {
    string value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* makeStudentTree() {
    TreeNode *temp = new TreeNode;
    temp->value = "Jerry";
    temp->left = new TreeNode;
    temp->left->value = "Armin";
    temp->left->right = new TreeNode;
    temp->left->right->value = "Ayaan";
    temp->left->left = new TreeNode;
    temp->left->left->value = "Aidan";
    temp->left->left->left = new TreeNode;
    temp->left->left->left->value = "Aarav";
    temp->left->right->right = new TreeNode;
    temp->left->right->right->value = "Ben";
    temp->right = new TreeNode;
    temp->right->value = "Paul";
    temp->right->left = new TreeNode;
    temp->right->left->value = "Lucy";
    temp->right->left->left = new TreeNode;
    temp->right->left->left->value = "Leila";
    temp->right->left->right = new TreeNode;
    temp->right->left->right->value = "Nic";
    temp->right->right = new TreeNode;
    temp->right->right->value = "Theo";
    return temp;
}



int main() {
    cout << "Hello, Binary Trees123!" << endl;
    TreeNode *root = makeStudentTree();
    return 0;
}
