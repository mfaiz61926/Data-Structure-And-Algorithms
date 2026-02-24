#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    vector<vector<int>> dist;
    int n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isPossible(int mid) {
        if (dist[0][0] < mid || dist[n-1][n-1] < mid)
            return false;

        DisjointSet ds(n * n);

        auto id = [&](int i, int j) {
            return i * n + j;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] < mid) continue;

                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                        dist[ni][nj] >= mid) {
                        ds.unionBySize(id(i, j), id(ni, nj));
                    }
                }
            }
        }

        return ds.findUPar(id(0,0)) == ds.findUPar(id(n - 1, n - 1));
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        dist.assign(n, vector<int>(n, 1e9));

        queue<pair<int,int>> q;

        // Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int low = 0, high = n*n, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};