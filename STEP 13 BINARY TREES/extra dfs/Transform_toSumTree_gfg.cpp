// Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    void toSumTree(Node *root) {
        // code here
        if(!root) return;
        if(!root->left && !root->right) root->data = 0;
        
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        
        root->data = sum;
        
        toSumTree(root->left);
        toSumTree(root->right);
        
        int sum1 = 0;
        if(root->left) sum1 += root->left->data;
        if(root->right) sum1 += root->right->data;
        
        root->data += sum1;
    }
};