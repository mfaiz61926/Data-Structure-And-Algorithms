#include <bits/stdc++.h> 
using namespace std;
//changed some structure of tree

    class BinaryTreeNode {

      public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {

            this -> data = data;
            left = NULL;
            right = NULL;
        }

        // ~BinaryTreeNode() {
            
        //     if (left)
        //         delete left;
        //     if (right)
        //         delete right;
        // }
    };




int findClosestElement(BinaryTreeNode* node, int k){
    // Write your code here.
    int ans = node->data;
    BinaryTreeNode* temp = node;

    while(temp){
        if(abs(k - temp->data) < abs(k - ans)){
            ans = temp->data;
        }else if(abs(k - temp->data) == abs(k - ans)){
            ans = min(ans, temp->data);
        }

        if(temp->data == k) return k;

        if(temp->data > k){
            temp = temp->left;

        }
        else{
            temp = temp->right;
        }

    }
    return ans;
}