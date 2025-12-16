
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int cnt = 0;
    void dfs(TreeNode* root, int s, long long sum){
        if(!root) return;
     
        sum+=root->val;
        if(sum == s)cnt++;
        dfs(root->left, s, sum);
        dfs(root->right, s, sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return cnt;
        dfs(root, targetSum, 0LL);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return cnt;
    }
};