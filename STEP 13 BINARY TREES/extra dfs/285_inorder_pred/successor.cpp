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




class Solution {
public:
    // Function to find the inorder 
    // successor of a node in a BST
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // Store the inorder traversal of the tree
        vector<int> inorder;
        // Perform in-order traversal to
        // generate the sorted list
        inorderTraversal(root, inorder);
        
        // Binary search to find the
        // index of the node's value
        int idx = binarySearch(inorder, p->val);
        
        // If index is out of range or it's the
        // last element, return nullptr
        if (idx == inorder.size() - 1 || idx == -1) {
            return nullptr;
        }
        
        // Return the next element
        // as the inorder successor
        return new TreeNode(inorder[idx + 1]);
    }
    
    // Function to perform in-order traversal
    // and store in 'inorder' vector
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        // Base case: If the node is NULL, return
        if (root == NULL) {
            return;
        }
        
        // Traverse left subtree
        inorderTraversal(root->left, inorder);
        
        // Store current node's value
        // in 'inorder' vector
        inorder.push_back(root->val);
        
        // Traverse right subtree
        inorderTraversal(root->right, inorder);
    }
    
    // Function to perform
    // binary search on array
    int binarySearch(vector<int>& arr, int target) {
        // Initialize pointers for binary search
        int left = 0;
        int right = arr.size() - 1;
        
        // Binary search algorithm to find the
        // index of the target value
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If target found, return the index
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // If target not found,
        // return the index for insertion
        return left == arr.size() ? -1 : left;
    }
};