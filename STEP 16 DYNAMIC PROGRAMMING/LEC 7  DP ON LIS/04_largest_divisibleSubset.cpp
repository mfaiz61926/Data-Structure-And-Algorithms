#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        vector<int>par(n, -1);

        int last_idx = 0;
        int lis = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0 || nums[j] %nums[i]==0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        par[i] = j;
                        if(lis < dp[i]){
                            lis  = dp[i];
                            last_idx = i;
                        }
                    }
                }
            }
        }

        vector<int> ans ;
        while (last_idx != -1){
            ans.push_back(nums[last_idx]);
            last_idx = par[last_idx];
        }
        reverse (ans.begin(), ans.end());
        return ans;
    }
};