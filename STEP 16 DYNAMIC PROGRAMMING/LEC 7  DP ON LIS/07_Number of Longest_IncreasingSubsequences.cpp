// I DID THIS IS MY LOGIC
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , 1);
        vector<int>cnt(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j] + 1){
                        cnt[i]+= cnt[j];
                    }
                }
                
            }
        }
        int cnt1 = 0;
        int mx = *max_element(dp.begin(), dp.end());
        for(int i = 0; i < n; i++){
            if(dp[i] == mx) cnt1 += cnt[i];
        }
        
        return cnt1;
    }
};


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int  n = nums.size();
        vector<int>dp(n, 1);
        vector<int>cnt(n, 1);

        int mx = 1;
        for(int i = 0; i < n; i++){
            for(int p = 0; p < i; p++){
                if(nums[i] > nums[p] && dp[p] + 1 > dp[i]){
                    dp[i] = dp[p] + 1;
                    cnt[i] = cnt[p];
                }
                else if(nums[i] > nums[p] && dp[p] + 1 == dp[i]){
                    cnt[i] += cnt[p];
                }
            }
            mx = max(mx, dp[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == mx) ans += cnt[i];
        }

        return ans;
    }
};