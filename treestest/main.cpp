#include <iostream>

#include <set>

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
    root->right->right->right = new TreeNode();
    root->right->right->right->value = 9;
    root->right->right->right->right = new TreeNode();
    root->right->right->right->right->value = 10;
    return root;
}

bool contains(TreeNode *root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == value) {
        return true;
    }
    if (value < root->value) {
        return contains(root->left, value);
    } else {
        return contains(root->right, value);
    }
}

//problem #0
int countFavoriteNumbers(TreeNode* tree, const set<int> &favorites){
    if (tree == nullptr) return 0;
    int count = 0;
    if (favorites.count(tree->value) == 1) count++;
    count += countFavoriteNumbers(tree->left, favorites);
    count += countFavoriteNumbers(tree->right, favorites);
    return count;
}

//problem #1
bool hasPathSum(TreeNode* tree, int sum){
    if (tree == nullptr) return false;
    if (sum == tree->value && tree->left == nullptr && tree->right == nullptr) return true;
    return hasPathSum(tree->left, sum - tree->value) || hasPathSum(tree->right, sum - tree->value);
}

//problem #2
int differenceHelper(TreeNode* tree, int level){
    if(tree == nullptr) return 0;
    if(level%2 == 0) return tree->value + differenceHelper(tree->left, level+1) + differenceHelper(tree->right, level+1);
    else return differenceHelper(tree->left, level+1) + differenceHelper(tree->right, level+1) - tree->value;
}

int getLevelSumDifference(TreeNode* tree){
    return differenceHelper(tree, 0);
}


int getLevelSumDifference2(TreeNode *tree) {
    if (tree == nullptr) return 0;
    return tree->value - getLevelSumDifference(tree->left) - getLevelSumDifference(tree->right);
}

int main() {
    cout << "Hello, World!" << endl;
    TreeNode *root = makeTestTree();
    set<int> favorites;
    favorites.insert(2);
    favorites.insert(3);
    favorites.insert(8);
    favorites.insert(20);
    cout << getLevelSumDifference2 (root) << endl;
    cout << countFavoriteNumbers(root, favorites) << endl;
    cout << hasPathSum(root, 29) << endl;
    return 0;
}