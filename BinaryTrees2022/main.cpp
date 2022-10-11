#include <iostream>
#include <vector>
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

int height(TreeNode* tree){
    if (tree == nullptr) return 0;
    return 1 + max(height(tree->left), height(tree->right));
}

int countAs(TreeNode *tree){
    if (tree == nullptr) return 0;
    return countAs(tree->value) + countAs(tree->left) + countAs(tree->right);
}

void printTree(TreeNode* tree){
    if (tree == nullptr) return;
    printTree(tree->left);
    cout << tree->value << endl;
    printTree(tree->right);
}

bool isEqual(TreeNode* tree1, TreeNode* tree2){
    if (tree1 == nullptr && tree2 == nullptr) return true;
    if (tree1 == nullptr || tree2 == nullptr) return false;
    return tree1->value == tree2->value && isEqual(tree1->left, tree2->left) && isEqual(tree1->right, tree2->right);
}

int countLeaves(TreeNode* tree){
    if (tree == nullptr) return 0;
    if (!tree->left && !tree->right) return 1;
    return countLeaves(tree->left) + countLeaves(tree->right);
}

string getFirst(TreeNode *tree){
    if (tree == nullptr) return "";
    if (!tree->left && !tree->right) return tree->value;
    return getFirst(tree->left);

    /*interative soln
     * while(tree->left != nullptr){
     *    tree = tree->left;
     *    }
     *    return tree->value;
     *
     * */
}

void getVectorHelper(TreeNode* tree, vector<string> &vec){
    if (tree == nullptr) return;
    getVectorHelper(tree->left, vec);
    vec.push_back(tree->value);
    getVectorHelper(tree->right, vec);
}

vector<string> getVector(TreeNode *tree){
    vector<string> result;
    getVectorHelper(tree, result);
    return result;
}

void insertBST(TreeNode* &tree, string str){
    if (tree == nullptr){
        tree = new TreeNode;
        tree->value = str;
        return;
    }
    if (str < tree->value) insertBST(tree->left, str);
    else if (str > tree->value) insertBST(tree->right, str);
}

bool containsBST(TreeNode *tree, string str){
    if (tree == nullptr) return false;
    if (tree->value == str) return true;
    if (str < tree->value) return containsBST(tree->left, str);
    return containsBST(tree->right, str);
}

int main() {
    cout << "Hello, Binary Trees1234!" << endl;
    TreeNode *root = makeStudentTree();
    cout << size(root) << endl;
    if (contains(root, "Ben"))
        cout << "Yes" << endl;
    cout << countAs(root) << endl;
    cout << height(root) << endl;
    printTree(root);
    if (isEqual(root, root))
        cout << "Yes" << endl;

    cout << countLeaves(root) << endl;
    cout << getFirst(root) << endl;
    vector<string> names = getVector(root);
    insertBST(root, "Kevin");
    if (containsBST(root, "Ben"))
        cout << "Yes" << endl;
    return 0;
}
