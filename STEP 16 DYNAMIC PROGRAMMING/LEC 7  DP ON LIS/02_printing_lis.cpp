#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        vector<int>dp(n, 1);
        vector<int>par(n, -1);
        
        int lis = 0;
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
        
        vector<int>ans;
        
        while(last_idx != -1){
            ans.push_back(arr[last_idx]);
            last_idx = par[last_idx];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
        
        
    }
};