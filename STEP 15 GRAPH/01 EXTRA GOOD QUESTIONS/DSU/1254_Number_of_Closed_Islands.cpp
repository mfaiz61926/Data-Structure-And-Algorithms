// Author : m_conq(Mohd Faiz);
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int>parent, size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) 
        return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_v = findUPar(v);
        int ulp_u = findUPar(u);

        if(ulp_v == ulp_u) return ;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    
    int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    DisjointSet ds(n * m);

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    // 1. Union adjacent land cells
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0){
                int cell = i * m + j;
                for(int k = 0; k < 4; k++){
                    int ni = i + dr[k];
                    int nj = j + dc[k];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m &&
                       grid[ni][nj] == 0){
                        ds.unionBySize(cell, ni * m + nj);
                    }
                }
            }
        }
    }

    // 2. Mark components touching boundary
    unordered_set<int> boundary;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0 &&
               (i == 0 || j == 0 || i == n-1 || j == m-1)){
                boundary.insert(ds.findUPar(i * m + j));
            }
        }
    }

    // 3. Count closed islands
    unordered_set<int> seen;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0){
                int root = ds.findUPar(i * m + j);
                if(boundary.count(root) == 0 && seen.count(root) == 0){
                    cnt++;
                    seen.insert(root);
                }
            }
        }
    }
    return cnt;
}

};