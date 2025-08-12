#include <bits/stdc++.h>
using namespace std;


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
    void levO(TreeNode* root, vector<vector<int>>&ans) {
        if(root == nullptr) return;
        queue<TreeNode*>q;
        q.push(root);
        bool ok = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int>level(size);
            for(int i =0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int idx = ok?i:(size-i-1);
                level[idx] = node->val;

                if(node -> left != nullptr) {
                    q.push(node -> left);
                }
                if(node -> right != nullptr) {
                    q.push(node -> right);
                }
            }
            ok = !ok;
            ans.push_back(level);
        }

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        levO(root,ans);
        return ans;
    }
};