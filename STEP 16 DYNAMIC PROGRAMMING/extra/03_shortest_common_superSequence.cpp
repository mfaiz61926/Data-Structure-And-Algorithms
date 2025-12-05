class Solution {
  public:
  
    int  solve(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        int n = s1.size();
        int m = s2.size();
        
        // base case
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        
        
        int res = 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) res = 1 + solve(s1, s2, i-1, j-1, dp);
        else res = 1 + min(solve(s1, s2, i-1, j, dp) , solve(s1, s2, i, j-1, dp));
        
        
        return dp[i][j] = res;
    }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        // return solve(s1, s2, n-1, m-1, dp);
        for(int i = 0; i <= n; i++){
            dp[i][0] = i; 
        }
        for(int j = 0; j <= m; j++){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                //base case
                
                int res = 0;
                if(s1[i-1] == s2[j - 1]) res = 1 + dp[i - 1][j - 1];
                else res = 1 + min(dp[i - 1][j] , dp[i][j - 1]);
                
                dp[i][j] = res;
                
            }
        }
        return dp[n][m];
    }
};