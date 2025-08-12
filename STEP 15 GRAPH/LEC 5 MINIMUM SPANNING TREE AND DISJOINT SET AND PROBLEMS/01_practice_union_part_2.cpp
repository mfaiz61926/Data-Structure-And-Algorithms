#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int parent[1000];
    int sz[1000];
    void Make(int v){
        parent[v] = v;
        sz[v] = 1;
    }
    int Find(int v) {
        if(parent[v] == v){
            return v;
        }
        return parent[v] = Find(parent[v]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);

        if(a != b){
            if(sz[a] < sz[b]){
                swap(a, b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i = 0; i < n; i++){
            Make(i);
        }

        for(int u = 0; u < n; u++){
            for(auto v: graph[u]){
                int up = Find(u);
                int vp = Find(v);

                if(up == vp) return false;

                if(!graph[u].empty()){
                    Union(graph[u][0], v);
                }
            }
        }
        return true;
    }
};