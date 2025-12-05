// Tree node structure  used in the program
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class NodeValue {
    public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue largestBSTHelper(Node* root){
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
        
        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);
        
        if(left.maxNode < root->data && root->data < right.minNode){
            return NodeValue(
                             min(left.minNode, root->data), 
                             max(root->data, right.maxNode), 
                             left.maxSize + right.maxSize + 1);
        }
         return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    int largestBst(Node *root) {
        // Your code here
        return largestBSTHelper(root).maxSize;
        
    }
};