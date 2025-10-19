#include <bits/stdc++.h>
using namespace std;

// User function Template for C++       GFG PRACTICE  GO DOWN YOU WILL GET LEETCODE SOLUTION ALSO....
#define ll long long 
class Solution {
  public:
    int f(int i , int j, int isTrue, string &s, vector<vector<vector<ll>>>&dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return  s[i] == 'T' ? 1: 0;
            else return s[i] == 'F' ? 1 : 0;
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        ll ways = 0;
        for(int ind = i + 1; ind <= j - 1; ind += 2){
            ll lT = f(i, ind - 1, 1, s, dp);
            ll rT = f(ind + 1, j, 1, s, dp);
            ll lF = f(i, ind - 1, 0, s, dp);
            ll rF = f(ind + 1, j, 0, s, dp);
            
            if(s[ind] == '&'){
                if(isTrue) ways = ways + lT * rT;
                else ways = ways + lT * rF + lF * rT + lF * rF;
            }
            else if (s[ind] == '|'){
               if(isTrue) ways = ways + lT * rF + lF * rT + lT * rT;
               else ways = ways + lF * rF;
            }
            else{
                if(isTrue) ways = ways + lT * rF + lF * rT;
                else  ways = ways + lT * rT + lF * rF;
            }
        }
        return dp[i][j][isTrue] =  ways;
    }
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<ll>>>dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, 0)));
        // return f(0, n-1, 1, s, dp);
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= n - 1;j++){
                if(i > j) continue;
                
                for(int isTrue  = 0; isTrue <= 1; isTrue++){
                    
                    if(i == j){
                        if(isTrue) dp[i][j][isTrue] = s[i]=='T';
                        else dp[i][j][isTrue] = s[i] == 'F';
                        continue;
                    }
                    ll ways = 0;
                    for(int ind = i + 1; ind <= j - 1; ind += 2){
                        ll lT = dp[i][ind - 1][1];
                        ll rT = dp[ind + 1][j][1];
                        ll lF = dp[i][ind - 1][0];
                        ll rF = dp[ind + 1][j][0];
                        
                        if(s[ind] == '&'){
                            if(isTrue) ways = ways + lT * rT;
                            else ways = ways + lT * rF + lF * rT + lF * rF;
                        }
                        else if (s[ind] == '|'){
                           if(isTrue) ways = ways + lT * rF + lF * rT + lT * rT;
                           else ways = ways + lF * rF;
                        }
                        else{
                            if(isTrue) ways = ways + lT * rF + lF * rT;
                            else  ways = ways + lT * rT + lF * rF;
                        }
                    }
                    dp[i][j][isTrue] = ways;
                    
                }
                
            }
        }
        return dp[0][n - 1][1];
        
    }
};

// LEETCODE SOLUTION
class Solution {
public:
    char f(vector<char>&v, char op){
        if(op == '!'){
            return v[0] == 't' ? 'f' : 't';
        }
        if(op == '&'){
            return any_of(v.begin(), v.end(), [](char ch){return ch == 'f' ;}) ? 'f' : 't';
        } 
        if(op == '|'){
            return any_of(v.begin(), v.end(), [](char ch){return ch == 't' ;}) ? 't' : 'f';
        }
        return 'x'; //will not come here 
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char>st;
        for(int i = 0; i < n; i++){
            if(expression[i] ==',') continue;
            if(expression[i] == ')'){
                vector<char>v;
                while(st.top() != '('){
                    v.push_back(st.top()); st.pop();
                }
                st.pop();
                char op = st.top(); st.pop();
                st.push(f(v,op));
            }
            else{
                st.push(expression[i]);
            }
        }
        return st.top() == 't';
    }
};