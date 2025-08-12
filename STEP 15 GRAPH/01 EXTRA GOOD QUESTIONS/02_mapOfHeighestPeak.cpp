
// 1765. Map of Highest Peak
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>height(m,vector<int>(n, -1));
        queue<pair<int,int>>q;

        //init water cells
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        //BFS dir
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx>=0 && nx<m && ny>=0 && ny<n && height[nx][ny]==-1){
                    height[nx][ny] = height[x][y] +1;
                    q.push({nx,ny});
                }
            }
        }
        return height;
    }
};