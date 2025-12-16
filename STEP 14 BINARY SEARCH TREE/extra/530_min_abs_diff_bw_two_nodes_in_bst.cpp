/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prev = -1;
    int diff = 1e9;
    void inord(TreeNode* root){
        if(!root) return;
        inord(root->left);
        if(prev != -1) diff =min( abs(root->val - prev), diff);
        prev = root->val;
        inord(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inord(root);
        return diff;
    }
};