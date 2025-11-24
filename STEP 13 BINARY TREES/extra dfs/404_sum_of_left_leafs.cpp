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
    int sum = 0;
    void dfs(TreeNode* root, TreeNode* par){
        if(!root) return ;
        if(!root->left && !root->right){
            if(par && par->left && par->left == root){
                sum+=root->val;
            }
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,nullptr);
        return sum;
    }
};