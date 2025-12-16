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