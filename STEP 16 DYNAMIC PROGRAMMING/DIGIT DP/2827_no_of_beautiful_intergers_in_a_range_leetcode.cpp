#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[11][2][11][11][21][2];
    int solve(string &s, int idx, int tight, int cntE, int cntO, int mod, int started, int k){
        if(idx == s.size()){
            return started && (cntE == cntO) && (mod == 0);
        }

        if(dp[idx][tight][cntE][cntO][mod][started] != -1) return dp[idx][tight][cntE][cntO][mod][started];
        int limit = (tight ? s[idx] - '0' : 9);
        int ans = 0;

        for(int i = 0; i <= limit; i++){
            int ntight = (tight & (i == s[idx] - '0'));

            //leading 0's
            if(!started && i == 0){
                ans += solve(s, idx + 1, ntight, cntE, cntO, 0, 0, k);
            }
            else {
                int nmod = (mod * 10 + i) % k;
                if(i % 2 == 0){
                    ans += solve(s, idx + 1, ntight, cntE + 1, cntO, nmod, 1, k);
                }
                else ans += solve(s, idx + 1, ntight, cntE, cntO + 1, nmod, 1, k);
            }
            
        }

        return dp[idx][tight][cntE][cntO][mod][started] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {

        string right = to_string(high);
        memset(dp, -1, sizeof(dp));
        int ansR = solve(right, 0, 1, 0, 0, 0, 0, k);

        string left = to_string(low - 1);
        memset(dp, -1, sizeof(dp));
        int ansL = solve(left, 0, 1, 0, 0, 0, 0, k);

        return ansR - ansL;        
    }
};