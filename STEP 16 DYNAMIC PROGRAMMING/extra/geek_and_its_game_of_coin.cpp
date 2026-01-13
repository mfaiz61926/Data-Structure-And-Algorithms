
class Solution {
  public:
//   int ok = true;
    int dp[100005];
    bool findW(int n, int x, int y) {
        // code here
        if(n==0) return false;

        if(dp[n] != -1) return dp[n];
        
        if( !findW(n-1,x,y) || n-x >=0 && !findW(n-x, x, y) || n-y >= 0 &&  !findW(n-y, x, y))
            return dp[n] = true;
            
        return dp[n] = false;
       
    }
    
    int findWinner(int n, int x, int y){
        // if(n == 0) return false;
        memset(dp, 0 , sizeof(dp));
        // return findW(n, x, y);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n ;i++){
            if(i - 1 >= 0 && !dp[i - 1] ||
               i - x >= 0 && !dp[i - x] ||
               i - y >= 0 && !dp[i - y])  dp[i] = 1;
            else dp[i] = 0;
        }
        return dp[n];
    }
};
