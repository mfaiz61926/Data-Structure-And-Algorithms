#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minX, minY, maxX, maxY;
    int n, m;

    void dfs(vector<string>& image, int x, int y, vector<vector<int>>& vis) {
        if (x < 0 || x >= n || y < 0 || y >= m || 
            image[x][y] == '0' || vis[x][y]) 
            return;

        vis[x][y] = 1;

        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &d : dir)
            dfs(image, x + d[0], y + d[1], vis);
    }

    int minArea(vector<string> &image, int x, int y) {
        n = image.size();
        m = image[0].size();

        minX = maxX = x;
        minY = maxY = y;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(image, x, y, vis);

        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};
