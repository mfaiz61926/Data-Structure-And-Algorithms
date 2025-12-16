#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int t[301];
    unordered_set<string>st;
    bool solve(int idx, string &s){
        if(idx == n) return true;
        
        if(st.find(s.substr(idx, n - idx)) != st.end()) return true;
        
        if(t[idx] != -1) return t[idx];
        
        for(int l = 1; l <= n; l++){
            string temp = s.substr(idx, l);
            if(st.find(temp)!=st.end() && solve(idx+l, s)){
                return t[idx] = true;
            }
        }

        return t[idx] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(t, -1, sizeof(t));
        for(auto &it : wordDict){
            st.insert(it);
        }

        return solve(0, s);
    }
};


//TABULATION
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        vector<int>dp(n+1, 0);

        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                string temp = s.substr(j, i - j);
                if(st.find(temp) != st.end() && dp[j]){
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }
};