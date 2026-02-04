#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPal(int i, int j, string&s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, int n, string &s, vector<int>&dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int mn = 1e9;
        for(int j = i; j < n; j++){
            if(isPal(i, j, s)){
                int cost = 1 + f(j + 1, n, s, dp);
                mn = min(mn, cost);
            }
        }
        return dp[i] =  mn;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // return f(0, n, s, dp) - 1;

        for(int i = n - 1; i >= 0; i--){
            int mn = 1e9;
            for(int j = i; j < n; j++){
                if(isPal(i, j, s)){
                    int cost = 1 + dp[j + 1];
                    mn = min(mn, cost);
                }
            }
            dp[i] = mn;
        }
        return dp[0] - 1 ;
    }
};