#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    Node* delNode(Node* root, int x) {
        // code here
        if(!root) return nullptr;
        
        if(x < root->data){
            root->left = delNode(root->left, x);
            return root;
        }
        else if(x > root->data){
            root->right = delNode(root->right, x);
            return root;
        }
        else{
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if(!root->left){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node* par = root;
                Node* child = root->left;
                while(child->right)par = child,  child = child->right;
                if(root == par){
                    child->right = root->right;
                    delete root;
                    return child;
                }else{
                    par->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                
                
            }
        }
        
        return nullptr;    }
};