#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
  vector<Node*>ans;
  void inorder(Node*root){
      if(!root) return ;
      inorder(root->left);
      ans.push_back(root);
      inorder(root->right);
  }
    vector<Node*> findPreSuc(Node* root, int k) {
        // code here
        vector<Node*>res;
        inorder(root);
        int n = ans.size();
        bool ok = true;
        Node* pre = nullptr;
        Node* succ = nullptr;
        for(int i = 0; i < n; i++){
            if(ans[i]->data < k){
                pre = ans[i];
            }
            if(ans[i]->data > k && ok){
                succ = ans[i];
                ok = false;
            }
        }
        
        return { pre, succ};
        
        
    }
};