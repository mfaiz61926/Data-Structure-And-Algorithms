#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind, vector<int> &num, int k, vector<int> &dp) {
        int n = num.size();
        if (ind == n) return 0;

        if (dp[ind] != -1) return dp[ind];

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + f(j + 1, num, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, 0);
        // return f(0, arr, k, dp);
        for(int i = n - 1; i >= 0; i--){
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

            for (int j = i; j < min(i + k, n); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};