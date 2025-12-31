#include <bits/stdc++.h>
using namespace std;
// good dsu with reverse time technique.... very cool do it again...
// link -> https://leetcode.com/problems/last-day-where-you-can-still-cross/?envType=daily-question&envId=2025-12-31
class DisjointSet {
    public : 
    vector<int>parent, size;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);

    }

    void unionBySize(int u, int v){
        int ul = findUPar(u);
        int vl = findUPar(v);

        if(ul == vl) return ;
        if(size[ul] > size[vl]){
            parent[vl] = ul;
            size[ul] += size[vl];
        }
        else{
            parent[ul] = vl;
            size[vl] += size[ul];
        }
    }
};
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int tot = row * col;
        int top = tot;
        int bottom = tot + 1;

        DisjointSet ds(tot + 2);
        vector<vector<int>>mat(row, vector<int>(col, 0));
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int day = cells.size() - 1; day >= 0; day--){
            int r = cells[day][0]-1;
            int c = cells[day][1]-1;
            mat[r][c] = 1;
            int cellno = r * col + c;

            if(r == 0) ds.unionBySize(cellno, top);
            if(r == row - 1) ds.unionBySize(cellno, bottom);

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 &&  nr < row && nc >= 0 && nc < col && mat[nr][nc]){
                    ds.unionBySize(cellno, nr * col + nc);
                }
            }

            if(ds.findUPar(top) == ds.findUPar(bottom)) return day;


        }
        
        
        return 0;
    }
};