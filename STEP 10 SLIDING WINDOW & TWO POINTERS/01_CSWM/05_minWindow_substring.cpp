#include <bits/stdc++.h>
using namespace std;
//link ->  https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), reqcnt = t.size();
        if(reqcnt > n) return "";
        int start_idx = -1;
        int l = 0; 
        int minw = 1e9;
        map<char,int>mp;
        for(char ch : t){
            mp[ch]++;
        }
        for(int r = 0; r < n; r++){
            if(mp[s[r]]>0) reqcnt--;
            mp[s[r]]--;
            while(reqcnt == 0){
                if(minw > r - l + 1){
                    minw = r - l + 1;
                    start_idx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) reqcnt++;
                l++;
            }

        }
        return minw==1e9? "":s.substr(start_idx, minw);
    }
};