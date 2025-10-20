#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> res;
    
    bool isSafe(int i , int j, int n){
        return  i >= 0 && i < n && j >= 0 && j < n;
    }
    void f(int i , int j , vector<vector<int>>&maze, int n , string &s){
        if(!isSafe(i, j, n) || maze[i][j] == 0) return ;
        
        if(i == n - 1 &&  j == n - 1){
            res.push_back(s);
            return;
        }
        
        maze[i][j] = 0;
        
        s.push_back('D');
        f(i + 1, j, maze, n, s);
        s.pop_back();
        
        s.push_back('R');
        f(i, j + 1, maze, n , s);
        s.pop_back();
        
       
        
        s.push_back('L');
        f(i, j - 1, maze, n, s);
        s.pop_back();
        
         s.push_back('U');
        f(i-1, j, maze, n, s);
        s.pop_back();
        
        maze[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        string s  = "";
        f(0,0,maze, n, s);
        sort(res.begin(), res.end());
        return res;
        
    }
};