#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[10001];

    int solve(int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int result = INT_MAX;

        for (int i = 1; i * i<= n; i++) {
            result = min(result, 1 + solve(n - i*i));
        }

        return dp[n] = result;
    }

    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, 1e9);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i] , dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};
