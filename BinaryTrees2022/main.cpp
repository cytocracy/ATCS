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

int size(TreeNode* tree){
    if (tree == nullptr) return 0;
    return 1 + size(tree->left) + size(tree->right);
}

bool contains(TreeNode* tree, string str){
    if (tree == nullptr) return false;
    if (tree->value == str) return true;
    return contains(tree->left, str) || contains(tree->right, str);
}

int countAs(string str){
    if(str.length() == 0) return 0;
    if(tolower(str[0]) == 'a') return 1+countAs(str.substr(1));
    return countAs(str.substr(1));
}

int countAs(TreeNode *tree){
    if (tree == nullptr) return 0;
    return countAs(tree->value) + countAs(tree->left) + countAs(tree->right);
}

bool allEvenLength(TreeNode* tree){
    if (tree == nullptr) return true;
    if (tree->value.length() % 2 != 0) return false;
    return allEvenLength(tree->left) && allEvenLength(tree->right);
}

void flipTree(TreeNode* tree){
    if(tree == nullptr) return;
    TreeNode* left = tree->left;
    TreeNode* right = tree->right;
    tree->left = right;
    tree->right = left;
    flipTree(tree->left);
    flipTree(tree->right);
}

TreeNode* makeFullTree(string str, int level){
    if(level <= 0) return nullptr;
    TreeNode* treeNode = new TreeNode;
    tree->value = str;
    tree->left = makeFullTree(str, level-1);
    tree->right = makeFullTree(str, level-1);
    return tree;
}

void removeLeaves(TreeNode* &tree){
    if(tree==nullptr) return;
    if(tree->left==nullptr && tree->right==nullptr){
        delete tree;
        tree = nullptr;
        return;
    }
    removeLeaves(tree->left);
    removeLeaves(tree->right);
}

int main() {
    cout << "Hello, Binary Trees12345678901!" << endl;
    TreeNode *root = makeStudentTree();
    cout << size(root) << endl;
    if (contains(root, "Ben"))
        cout << "Yes" << endl;
    cout << countAs(root) << endl;
    return 0;
}
