#include <bits/stdc++.h>
using namespace std;
//LEETCODE
class Solution {
public:
    vector<vector<string>>res;
    bool isValid(vector<string>&board, int n, int i , int j){
        for(int r = i; r >= 0; r--){
            if(board[r][j] == 'Q') return false;
        }

        //left updiag
        for(int r = i, c = j; r >=0 && c >=0; r--,c--){
            if(board[r][c] == 'Q') return false;
        }

        //right  updiagonal

        for(int r = i, c = j; r >= 0 && c < n; r--,c++){
            if(board[r][c] == 'Q') return false;
        }

        return true;

    }
    void solve(int i , int n, vector<string>&board){
        if(i == n){
            res.push_back(board);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isValid(board, n, i, j)){
                board[i][j] = 'Q';
                solve(i+1, n, board);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==0) return {};
        vector<string>board(n, string(n, '.'));
        solve(0, n, board);
        return  res;
    }
};



//GFG FOR INT VECTOR AS ANS
class Solution {
  public:
    vector<vector<string>> res;
    
    bool isValid(vector<string>&board, int n, int i , int j){
        for(int r = i; r >= 0; r--){
            if(board[r][j] == 'Q') return false;
        }

        //left updiag
        for(int r = i, c = j; r >=0 && c >=0; r--,c--){
            if(board[r][c] == 'Q') return false;
        }

        //right  updiagonal

        for(int r = i, c = j; r >= 0 && c < n; r--,c++){
            if(board[r][c] == 'Q') return false;
        }

        return true;

    } 
    
    
    void solve(int i , int n, vector<string>&board){
        if(i == n){
            res.push_back(board);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isValid(board, n, i, j)){
                board[i][j] = 'Q';
                solve(i+1, n, board);
                board[i][j] = '.';
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        if(n==0) return {};
        vector<string>board(n, string(n, '.'));
        solve(0, n, board);
        
        int nn = res.size();
        
        vector<vector<int>>v;
        for(int k = 0; k < res.size(); k++){
            vector<int>temp(n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(res[k][i][j] == 'Q'){
                        temp[i] = j+1;
                    }
                }
            }
            v.push_back(temp);
          
        }
        
        
        return v;
        
    }
};