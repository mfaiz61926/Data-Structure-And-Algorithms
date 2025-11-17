
// class Solution { // BACKTRACKING APPROACH
// public:
//     void solve(TreeNode* root, vector<string>&ans, string& res){
//         if(!root) return;
//         int cur_size = res.size();
//         res+=to_string(root->val);
//         if(!root->left && !root->right){
//             ans.push_back(res);
//         }
//         else{
//             res+=("->");
//             solve(root->left, ans, res);
//             solve(root->right, ans, res);
//         }
//         res.resize(cur_size);
//     }
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string>ans;
//         string res = "";
//         solve(root, ans, res);
//         return ans;
//     }
// };

class Solution { // RECURSIVE APPROACH
public:
    void dfs(TreeNode* root, vector<string>&ans, string path){
        if(!root) return;
         // Append current node value
        if (!path.empty()) path += "->";
        path += to_string(root->val);

        // If leaf node, store the path
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        dfs(root->left, ans, path);
        dfs(root->right, ans, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string res = "";
        dfs(root, ans, res);
        return ans;
    }
};