#include <bits/stdc++.h>
using namespace std;

class Solution { //MEMOISATION
  public:
    int f(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mn = 1e9;
        for(int k = i; k <= j - 1; k++){
            int op = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            mn = min(mn, op);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return f(1, n - 1, arr, dp);
    }
};

// TABULATION MY TECHNIQUE

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    int n = N;
    vector<vector<int>>dp(N, vector<int>(N, 0));

    for(int i = n-1; i >= 1; i--){
        for(int j = i+1; j < n; j++){
            int mn = INT_MAX;
            for(int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k+1][j] + arr[i - 1] * arr[k] * arr[j];
                mn = min(mn, cost);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][n-1];
}

//bottom up ....02_question.
class Solution {
  public:
    int f(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mn = 1e9;
        for(int k = i; k <= j - 1; k++){
            int op = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            mn = min(mn, op);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i = n -1 ; i >= 1; i--){
            for(int j = i + 1; j < n; j++){
                int mn = 1e9;
                for(int k = i; k <= j - 1; k++){
                    int op = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mn = min(mn, op);
                }
                dp[i][j] = mn;
       
            }
        }
        return dp[1][n - 1];
    }
};