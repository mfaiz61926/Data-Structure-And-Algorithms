#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[101];
    int solve(string &s, int i){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        // DO FOR ONE NUMBER
        int ways = solve(s, i + 1);

        //for second number
        if(i + 1 < s.size()){
            int num = (s[i] - '0')*10 + s[i + 1] - '0';
            if(num >= 10 && num <= 26){
                ways += solve(s, i + 2);
            }
        }

        return dp[i] = ways;
        
    }
    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s,0);
    }
};