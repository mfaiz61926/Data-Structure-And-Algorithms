// User function Template for C++

// /* Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    bool dfs(Node* root, int &cnt){
        if(!root) return true;
        
        bool left = dfs(root->left, cnt);
        bool right = dfs(root->right, cnt);
        
        if(!left || !right) return false;
        
        if(root->left && root->left->data != root->data) return false;
        if(root->right && root->right->data != root->data) return false;
        
        cnt++;
        return true;
    }
    int singlevalued(Node *root) {
        // code here
        int cnt = 0;
        dfs(root,cnt);
        return cnt;
    }
};
