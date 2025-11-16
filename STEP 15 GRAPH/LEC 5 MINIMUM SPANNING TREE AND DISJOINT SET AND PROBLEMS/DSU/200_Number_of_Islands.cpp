#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    public : 
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return ;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};


class Solution {
public:


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        DisjointSet ds (n*m);


        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    int node = i *m + j;
                    
                    for(int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if(nr>=0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == '1'){
                            int adjNode = nr*m + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        int cnt = 0;
        unordered_set<int>seen;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    int node = i * m + j;
                    seen.insert(ds.findUPar(node));
                }
                
            }
        }

        return seen.size();
    }
};