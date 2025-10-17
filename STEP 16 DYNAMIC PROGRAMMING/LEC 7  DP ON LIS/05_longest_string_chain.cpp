#include <bits/stdc++.h>
using namespace std;

class Solution {  // i did
public:
    bool fesible(string a, string b){
        if(a.size() != 1 + b.size()) return false;
        int i = 0;
        int j = 0;
        while(i < a.size()){
            if(j < b.size() && a[i] == b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j == b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int lis = 1;
        
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });

        vector<int>dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(fesible(words[i], words[j])){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        if(dp[i] > lis){
                            lis = dp[i];
                        }
                    }
                }
            }
        }
        return lis;
    }
};

class Solution {
public:
    bool compare(string &a, string &b){
        if(a.size() != b.size() + 1) return false;

        int first = 0; 
        int sec = 0;
        while(first < a.size()){
            if(sec < b.size() && a[first] == b[sec]){
                first++;
                sec++;
            }
            else first++;
        }
        if(first == a.size() && sec == b.size()) return true;
        else return false;
    }
    static bool comp(const string &a, const string &b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),comp);

        vector<int>dp(n, 1);
        int mx = 1;
        for(int i = 0; i < n; i++){
            for(int p = 0; p < i; p++){
                if(compare(words[i], words[p]) && 1 + dp[p] > dp[i]){
                    dp[i] = dp[p] + 1;
                }
            }
            if(dp[i] > mx){
                mx = dp[i];
            }
        }
        return mx;
    }
};