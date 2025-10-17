#include <bits/stdc++.h>
using  namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) { //its a op code master it.
        int n = arr.size();
        
        vector<int>dp(n, 1);
        vector<int>par(n, -1);
        
        int lis = 1;
        int last_idx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        par[i] = j;
                        if(lis < dp[i]){
                           lis = dp[i];
                           last_idx = i;
                        }
                    }
                }
            }
        }
        
        return lis;
    }
};

class Solution {
public:
    int f(int i, int p_i, int n, vector<int>&nums, vector<vector<int>>&dp){
        if(i == n) return 0;
        if(dp[i][p_i + 1] != -1) return dp[i][p_i + 1];

        int nt = f(i + 1, p_i, n, nums, dp);
        int tk = 0;
        if(p_i == -1 || nums[i] > nums[p_i]){
            tk = 1 + f(i + 1, i, n, nums, dp);
        }
        return dp[i][p_i + 1] = max(tk, nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
        // return f(0, -1, n, nums, dp);
        for(int i = n - 1; i >= 0; i--){
            for(int pi = i - 1; pi >=-1; pi--){
                int nt = dp[i + 1][pi + 1];
                int tk = 0;
                if(pi == -1 || nums[i] > nums[pi]){
                    tk = 1 + dp[i + 1][i + 1];
                }
                dp[i][pi + 1] = max(tk, nt);
            }
        }
        return dp[0][0];
    }
};
// SPACE OPTIMISATION
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>cur(n + 1, 0);
        vector<int>next(n + 1, 0);
        // return f(0, -1, n, nums, dp);
        for(int i = n - 1; i >= 0; i--){
            for(int pi = i - 1; pi >=-1; pi--){
                int nt = next[pi + 1];
                int tk = 0;
                if(pi == -1 || nums[i] > nums[pi]){
                    tk = 1 + next[i + 1];
                }
                cur[pi + 1] = max(tk, nt);
            }
            next = cur;
        }
        return next[0];
    }