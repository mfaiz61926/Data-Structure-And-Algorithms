class DisjointSet{
    
    public:
    vector<int>parent, size, rank;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            rank.resize(n+1,0);
            for(int i = 0; i <= n; i++){
                size[i] = 1;
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int cell = i * m + j;
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for(int k = 0; k < 4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 1){
                        ds.unionBySize(cell, nr*m + nc);
                    }
                }
                
            }
        }
        for(int i = 0; i < n*m; i++){
           if(grid[i / m][i % m] == 1 && ds.findUPar(i) == i){
                mx = max(mx, ds.size[i]);
            }
        }


        
    }
     return mx;   
    }
};