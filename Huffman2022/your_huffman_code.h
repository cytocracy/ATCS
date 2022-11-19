
#ifndef HUFFMAN_YOUR_HUFFMAN_CODE_H
#define HUFFMAN_YOUR_HUFFMAN_CODE_H

#include <map>
#include "huffman_helper.h"
using namespace std;

struct TreeNode {
    char ch;
    int weight;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        left = nullptr;
        right = nullptr;
    }
};
struct CompareTreeNode
{
    bool operator()(const TreeNode* lhs, const TreeNode* rhs) const
    {
        return lhs->weight > rhs->weight;
    }
};

void destroyTree(TreeNode* root){
    if(root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

void addPath(TreeNode* root, map<char, queue<Bit>>& paths, queue<Bit> currPath){
    if(root->left == nullptr && root->right == nullptr){
        paths[root->ch] = currPath;
        return;
    }
    if(root->left != nullptr){
        queue<Bit> leftPath = currPath;
        leftPath.push(0);
        addPath(root->left, paths, leftPath);
    }
    if(root->right != nullptr){
        queue<Bit> rightPath = currPath;
        rightPath.push(1);
        addPath(root->right, paths, rightPath);
    }
}

void flattenTree(EncodedData &data, TreeNode* root){
    if(root->left == nullptr && root->right == nullptr){
        data.treeShape.push(0);
        data.treeLeaves.push(root->ch);
        return;
    } else {
        data.treeShape.push(1);
        flattenTree(data, root->left);
        flattenTree(data, root->right);
    }
}

void huffmanAlg(priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> &pq){
    while(pq.size() > 1){
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();
        TreeNode* parent = new TreeNode();
        parent->left = left;
        parent->right = right;
        parent->weight = left->weight + right->weight;
        pq.push(parent);
    }
}

EncodedData createEncoding(map<char, queue<Bit>> &code, const string &text, TreeNode* &root){
    queue<Bit> encoded;
    for(char ch : text){
        queue<Bit> q = code[ch];
        while(!q.empty()){
            encoded.push(q.front());
            q.pop();
        }
    }

    EncodedData data;
    data.messageBits = encoded;
    flattenTree(data, root);
    destroyTree(root);
    return data;
}

EncodedData compress(string text) {
    map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> pq;

    for (auto it = freq.begin(); it != freq.end(); it++) {
        TreeNode* node = new TreeNode();
        node->ch = it->first;
        node->weight = it->second;
        pq.push(node);
    }

    huffmanAlg(pq);

    TreeNode* root = pq.top();
    map<char, queue<Bit>> code;
    addPath(root, code, queue<Bit>());

    return createEncoding(code, text, root);
}

TreeNode* buildTree(EncodedData& data){
    if(data.treeLeaves.empty()) return nullptr;

    TreeNode* root = new TreeNode;
    if(data.treeShape.front() == 0) {
        data.treeShape.pop();
        root->ch = data.treeLeaves.front();
        data.treeLeaves.pop();
    } else {
        data.treeShape.pop();
        root->left = buildTree(data);
        root->right = buildTree(data);
    }
    return root;
}

string decompress(EncodedData& data) {
    TreeNode* root = buildTree(data);
    string result;

    cout << "data.messageBits.size() = " << data.messageBits.size() << endl;
    while(!data.messageBits.empty()){
        TreeNode* cur = root;
        while(cur->left != nullptr && cur->right != nullptr){
            if(data.messageBits.front() == 0) cur = cur->left;
            else cur = cur->right;
            data.messageBits.pop();
        }
        result += cur->ch;
    }
    destroyTree(root);
    return result;
}

#endif //HUFFMAN_YOUR_HUFFMAN_CODE_H
