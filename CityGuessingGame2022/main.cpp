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
    string type = line.substr(0, 1);
    string value = line.substr(2);
    root = new TreeNode(line);
    if (type == "Q"){
        buildTree(fin, root->left);
        buildTree(fin, root->right);
    }
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
//    string rootValue;
//    getline(fin, rootValue);
//    root = new TreeNode(rootValue.substr(1));
    buildTree(fin, root);
    printTree(root);

    TreeNode* current = root;
    bool playing = true;
    while(playing){
        cout << current->value << endl;
        string answer;
        getline(cin, answer);
        if (answer == "Y"){
            current = current->left;
        } else if (answer == "N"){
            current = current->right;
        } else if (answer == "Q"){
            playing = false;
        }
    }


    cout << "Good bye!" << endl;

    return 0;
}