class Solution {
public:
    int solve(vector<int>&nums, int val, vector<int>&dp){
        if(val == 0) return 1;
        if(val < 0) return 0;

        if(dp[val] != -1) return dp[val];
        int ans = 0;
        for(auto &it : nums){
            ans += solve(nums, val - it, dp);
        }

        return dp[val] = ans;
    }
   int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long>dp(target+1,0LL);
        // return solve(nums, target, dp);
        dp[0] = 1;

        for(int i = 1; i <= target; i++){
            for(auto &it : nums){
                if(it <= i)
                dp[i] += dp[i - it];
                if(dp[i] > INT_MAX){
                    dp[i] = INT_MAX;
                }
            }
        }

        return (int)dp[target];
    }
};