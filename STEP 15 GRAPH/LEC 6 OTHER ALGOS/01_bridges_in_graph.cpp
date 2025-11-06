#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&vis, vector<int>&low, vector<int>&timeIn, vector<vector<int>>&bridges){
        vis[node] = 1;
        low[node] = timeIn[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent){
                continue;
            }
            if(vis[it]==0){
                dfs(it, node, adj, vis, low, timeIn, bridges);
                low[node] = min(low[node], low[it]);
                //bridge check
                if(low[it] > timeIn[node]){
                    bridges.push_back({it, node});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto &it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n, 0);
        vector<int>timeIn(n, 0);
        vector<int>low(n, 1e9);
        vector<vector<int>>bridges;
        dfs(0, -1, adj, vis, low , timeIn, bridges);
        return  bridges;
    }
};