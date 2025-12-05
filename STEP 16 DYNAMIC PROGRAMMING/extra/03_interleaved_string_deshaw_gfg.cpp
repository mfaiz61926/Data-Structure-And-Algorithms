#include <bits/stdc++.h>
using namespace std;

class Solution { // TLE;
  public:
    bool check(string &a, string &b, int i, int j){
        int n = a.size();
        int m = b.size();
        if(n-i !=m-j) return false;
        
        for(int k = 0; k < n - i; k++){
            if(a[k+i] != b[k+j]) return false;
        }
        return true;
    }
    bool solve(string &s1, string &s2, string & s3, int i, int j , int k, vector<vector<vector<int>>>&dp){
        //base case;
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        
        if(k == o && i==n && j == m) return true;
        
        if(k==o) return false;
        
        if(i==n) return check(s2, s3, j, k);
        if(j == m) return check(s1, s3, i, k);
        
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        bool res = false;
        
        if(s1[i] == s3[k])  res |=  solve(s1, s2, s3, i+1, j, k+1,dp);
        if(!res && s2[j] == s3[k]) res  |= solve(s1, s2, s3, i, j+1, k+1,dp);
        return dp[i][j][k] =  res;
        
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        
        if(o > n + m) return false;
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(o, -1)));
        
        return solve(s1, s2, s3, 0, 0, 0, dp);
        
    }
};




class Solution { // optimal 
  public:
    bool solve(string &s1, string &s2, string & s3, int i, int j , vector<vector<int>>&dp){
        //base case;
        int n = s1.size();
        int m = s2.size();
        int k = i + j;
        
        if(k == s3.size()) return (i == n && j == m);
        if(dp[i][j] != -1) return dp[i][j];
        
        

        bool res = false;
        
        if(i < n && s1[i] == s3[k])  res |=  solve(s1, s2, s3, i+1, j,dp);
        if(!res && j < m && s2[j] == s3[k])  res |= solve(s1, s2, s3, i, j+1,dp);
        return dp[i][j] =  res;
        
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        
        if(o > n + m) return false;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1, -1));
        
        return solve(s1, s2, s3, 0, 0, dp);
        
    }
};



class Solution { //tabulation
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();

        if (o != n + m) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        // Fill first row (only s2 can contribute)
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill first column (only s1 can contribute)
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // Fill the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[n][m];
    }
};
