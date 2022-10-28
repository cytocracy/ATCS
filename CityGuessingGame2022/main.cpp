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

bool isCity(TreeNode *node){
    if (node == nullptr) return false;
    if (node->left == nullptr && node->right == nullptr) return true;
    return false;
}

void buildTree(ifstream &fin, TreeNode* &root){
    string line;
    getline(fin, line);
    if (line.empty()) return;
    string type = line.substr(0, 1);
    string value = line.substr(1);
    root = new TreeNode(value);
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

void newCity(TreeNode* guess){
    cout << "Darn. What was your city?" << endl;
    string newCity;
    getline(cin, newCity);
    cout << "Please enter a question that would distinguish between" << guess->value<< " and " << newCity << ": ";
    string newQuestion;
    getline(cin, newQuestion);
    cout << "If you were thinking of " << newCity << ", what would the answer be? (y/n): ";
    string newAnswer;
    getline(cin, newAnswer);
    if (newAnswer == "y"){
        guess->left = new TreeNode(newCity);
        guess->right = new TreeNode(guess->value);
    } else {
        guess->left = new TreeNode(guess->value);
        guess->right = new TreeNode(newCity);
    }
    guess->value = newQuestion;
}

void gameLoop(TreeNode* current){
    while(!isCity(current)){
        cout << current->value << " (y/n)? ";
        string answer;
        getline(cin, answer);
        if (answer == "y"){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << "Is it " << current->value<< "? (y/n)? ";
    string answer;
    getline(cin, answer);
    if (answer == "y"){
        cout << "I win!" << endl;
    } else newCity(current);
}

void saveDataHelper(TreeNode* root, ofstream &fout){
    if (root == nullptr) return;
    if (isCity(root)){
        fout << "A" << root->value << endl;
    } else {
        fout << "Q" << root->value << endl;
        saveDataHelper(root->left, fout);
        saveDataHelper(root->right, fout);
    }
}

void saveData(TreeNode* root){
    cout << "Do you want to save the current city information to a file? (y/n): ";
    string answer;
    getline(cin, answer);
    if (answer == "y"){
        cout << "Please enter the filename: ";
        string filename;
        getline(cin, filename);
        ofstream fout(filename);
        if (fout.fail()){
            cout << "Error opening file" << endl;
            return;
        }
        saveDataHelper(root, fout);
    }
}

int main() {
    cout << "City Guessing Game" << endl << endl;
    cout << "Welcome to the City Guessing Game!" << endl;
    string filename;
    cout << "Enter the name of the data file: ";
    getline(cin, filename);
    TreeNode* root = nullptr;
    ifstream fin(filename.c_str());

    buildTree(fin, root);

    bool playing = true;
    while(playing){
        cout << "Think of a city. Press return when you are ready...";
        cin.get();
        gameLoop(root);
        cout << "Do you want to play again? (y/n): ";
        string answer;
        getline(cin, answer);
        if (answer == "n") playing = false;
    }

    saveData(root);

    cout << "Good bye!" << endl;
    return 0;
}