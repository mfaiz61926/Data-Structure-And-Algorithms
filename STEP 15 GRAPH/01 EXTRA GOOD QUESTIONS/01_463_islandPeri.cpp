// https://leetcode.com/problems/island-perimeter/description/
// 463. Island Perimeter
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans +=4;
                    int dr[]={-1,0,1,0};
                    int dc[]={0,1,0,-1};
                    for(int k=0;k<4;k++){
                        int nr = i+dr[k];
                        int nc = j+dc[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) ans--;
                    }
                }
            }
        }
        return ans;
    }
};




//DFS APPROACH
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += dfs(grid, r, c);
                }
            }
        }

        return perimeter;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        // Base cases for DFS recursion
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 1; // Water contributes 1 to perimeter
        }
        if (grid[r][c] == -1) {
            return 0; // Already visited land cell
        }

        // Mark cell as visited
        grid[r][c] = -1;

        // Explore neighbors (up, down, left, right)
        return (dfs(grid, r + 1, c) +
                dfs(grid, r - 1, c) +
                dfs(grid, r, c + 1) +
                dfs(grid, r, c - 1));
    }
};