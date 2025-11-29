#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution {
  public:
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    int ans = 1;
    
    void dfs(Node* root, int parent, int len){
        if(!root) return;
        
        if(root->data == parent + 1) len++;
        else len = 1;
        
        ans = max(ans, len); // maximise ans
        
        dfs(root->left, root->data, len);
        dfs(root->right, root->data, len);
    }
    
    int longestConsecutive(Node* root) {
        // Code here
        if(!root) return 0;
        dfs(root, root->data - 1, 0);
        return ans >=2 ? ans : -1;
    }
};