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

int main() {
    cout << "City Guessing Game" << endl << endl;
    cout << "Welcome to the city City Guessing Game!" << endl;
    string filename;
    cout << "Enter the name of the data file: ";
    getline(cin, filename);
    TreeNode* root = nullptr;
    ifstream fin(filename.c_str());

    // continue here
    // read the file and build the tree
    // then play the game


    cout << "Good bye!" << endl;

    return 0;
}