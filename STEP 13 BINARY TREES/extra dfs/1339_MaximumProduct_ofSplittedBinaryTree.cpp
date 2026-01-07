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
    long long mx = 0;
    int tot_sum = 0;
    const int MOD = 1e9+7;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        tot_sum += root->val;
        inorder(root->right);
    }

    long long dfs(TreeNode* root){
        if(!root) return 0LL;
        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long sum_subtree = left + right + root->val;

        mx = max(mx * 1LL, sum_subtree * (tot_sum - sum_subtree));
        
        return sum_subtree;

    }
    
    int maxProduct(TreeNode* root) {
        inorder(root);
        dfs(root);
        return mx % MOD;  
    }
};