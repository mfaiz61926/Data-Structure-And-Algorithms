#include <bits/stdc++.h>
using namespace std;

class Solution { //optimal DFS + DP
public:
    int dp[201][201];
    int dfs(vector<vector<int>>&mat, int i, int j){
        int n = mat.size();
        int m = mat[0].size();
        if(dp[i][j] != -1) return dp[i][j];
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int ans = 1;
        for(int k = 0; k < 4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m  && mat[i][j] < mat[nr][nc]){
                ans = max(ans, 1 + dfs(mat, nr, nc));
            }
        }
        return dp[i][j] = ans;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int res = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){  
                res = max(res, dfs(matrix, i, j));
            }
        }

        return res;
    }
};


class Solution {  //TOPO SORT LOGIC
public:
    bool isValid(int x, int y, int r, int c) {
        return x >= 0 && y >= 0 && x < r && y < c;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if (r == 0) return 0;
        int c = matrix[0].size();

        vector<vector<int>> inDegree(r, vector<int>(c, 0));
        vector<pair<int, int>> dirs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

     
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (auto dir : dirs) {
                    int curR = i + dir.first;
                    int curC = j + dir.second;
                
                    if (isValid(curR, curC, r, c) && matrix[i][j] < matrix[curR][curC]) {
                        inDegree[curR][curC]++;
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (inDegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int path = 0;
 
        while (!q.empty()) {
            int sz = q.size();
            path++;
            while (sz--) {
                int curR = q.front().first;
                int curC = q.front().second;
                q.pop();
                for (auto dir : dirs) {
                    int x = curR + dir.first;
                    int y = curC + dir.second;
                    if (isValid(x, y, r, c) && matrix[curR][curC] < matrix[x][y]) {
                        if (--inDegree[x][y] == 0) {
                            q.push({x, y});
                        }
                    }
                }
            }
        }

        return path;
    }
};