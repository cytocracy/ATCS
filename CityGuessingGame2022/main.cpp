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

void newCity(TreeNode* lastQ){
    cout << "I give up. What is it? ";
    string newCity;
    getline(cin, newCity);
    cout << "Please give me a question whose answer is yes for " << newCity << " and no for " << value << ": ";
    string newQuestion;
    getline(cin, newQuestion);
    cout << "And what is the answer for " << newCity << "? (y/n)? ";
    string newAnswer;
    getline(cin, newAnswer);
    TreeNode* newCityNode = new TreeNode("A " + newCity);
    TreeNode* newQuestionNode = new TreeNode("Q " + newQuestion);
    if (newAnswer == "y"){
        newQuestionNode->left = newCityNode;
        newQuestionNode->right = current;
    } else {
        newQuestionNode->left = current;
        newQuestionNode->right = newCityNode;
    }
    current->value = value;
    current = newQuestionNode;
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
//    printTree(root);

    TreeNode* current = root;
    bool playing = true;
    while(playing){
        cout << "Think of a city. Press return when you are ready...";
        cin.get();
        string type = current->value.substr(0, 1);
        string value = current->value.substr(1);
        if (type == "Q"){
            cout << value << " (y/n)? ";
            string answer;
            getline(cin, answer);
            if (answer == "y"){
                current = current->left;
            } else {
                current = current->right;
            }
        } else {
            cout << "Is it " << value << "? (y/n)? ";
            string answer;
            getline(cin, answer);
            if (answer == "y"){
                cout << "I win!" << endl;
            } else {
                newCity();
            }
        }
    }


    cout << "Good bye!" << endl;

    return 0;
}