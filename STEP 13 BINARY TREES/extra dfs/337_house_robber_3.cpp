class Solution {
public:
    map<TreeNode*, pair<int,int>> mp;

    int f(TreeNode* root, bool flag) {
        if (!root) return 0;

        // memo exists
        if (mp.count(root)) {
            if (flag && mp[root].first != -1) return mp[root].first;
            if (!flag && mp[root].second != -1) return mp[root].second;
        } else {
            mp[root] = {-1, -1}; // Initialize
        }

        int take = 0;
        if (flag)
            take = root->val + f(root->left, false) + f(root->right, false);

        int ntake = f(root->left, true) + f(root->right, true);

        if (flag) mp[root].first = max(take, ntake);
        else mp[root].second = ntake;

        return flag ? mp[root].first : mp[root].second;
    }

    int rob(TreeNode* root) {
        return f(root, true);
    }
};
