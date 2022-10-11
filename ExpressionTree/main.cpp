#include <iostream>
#include <stack>
using namespace std;

struct EComponent {
    string op;
    int number;
};

struct ETNode {
    ETNode *left, *right;
    EComponent value;
    ETNode(string oper) {
        value.op = oper;
        left = nullptr;
        right = nullptr;
    }
    ETNode(int num) {
        value.op = "#";
        value.number = num;
        left = nullptr;
        right = nullptr;
    }
    string tostring() {
        if (value.op != "#")
            return value.op;
        else
            return to_string(value.number);
    }
};

ETNode *buildExpressionTree() {
    ETNode *tree = new ETNode("*");
    tree->left = new ETNode("+");
    tree->left->left = new ETNode(2);
    tree->left->right = new ETNode(1);
    tree->right = new ETNode("-");
    tree->right->left = new ETNode("/");
    tree->right->left->left = new ETNode(60);
    tree->right->left->right = new ETNode(4);
    tree->right->right = new ETNode(6);
    return tree;
}

void printInOrder(ETNode* tree){
    if (tree == nullptr) return;
    printInOrder(tree->left);
    cout << tree->tostring() << " ";
    printInOrder(tree->right);
}

int main() {
    cout << "Hello, Expression Tree!" << endl;
    ETNode *root = buildExpressionTree();
    printInOrder(root);
    cout << endl;
    // printPostOrder(root);
    cout << endl;

    return 0;
}