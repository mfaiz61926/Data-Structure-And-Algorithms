#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool ham(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    int cnt = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != s2[i])cnt++;
        if(cnt > 1) return false;
    }
    if(cnt == 1) return true;
    return false;
}
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int>dp(n, 1);
        vector<int>par(n, -1);

        int lis = 0;
        int last_idx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(ham(words[i], words[j]) && (groups[i] != groups[j])){
                    if(dp[i] < dp[j] + 1){
                        dp[i]  = dp[j] + 1;
                        par[i] = j;
                        if(lis < dp[i]){
                            lis = dp[i];
                            last_idx = i;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        while(last_idx != -1){
            ans.push_back(words[last_idx]);
            last_idx = par[last_idx];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};