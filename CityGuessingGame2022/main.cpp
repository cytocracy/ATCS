#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TreeNode {
    string value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};


void buildTree(ifstream &fin, TreeNode* &root){
    string line;
    getline(fin, line);
    if (line.empty()) return;
    if(root->left == nullptr) root->left = new TreeNode(line);
    else root->right = new TreeNode(line);
    buildTree(fin, root->left);
    buildTree(fin, root->right);
}

void printTree(TreeNode* root){
    if (root == nullptr) return;
    cout << root->value << endl;
    printTree(root->left);
    printTree(root->right);
}

int main() {
    cout << "City Guessing Game" << endl << endl;
    cout << "Welcome to the city City Guessing Game!" << endl;
    string filename;
    cout << "Enter the name of the data file: ";
    getline(cin, filename);
    TreeNode* root = nullptr;
    ifstream fin(filename.c_str());
    string rootValue;
    getline(fin, rootValue);
    root = new TreeNode(rootValue.substr(1));
    buildTree(fin, root);

    bool playing = true;
    while(playing){
        TreeNode* curr = root;
        while(curr->left != nullptr && curr->right != nullptr){
            string answer;

        }

    }


    cout << "Good bye!" << endl;

    return 0;
}