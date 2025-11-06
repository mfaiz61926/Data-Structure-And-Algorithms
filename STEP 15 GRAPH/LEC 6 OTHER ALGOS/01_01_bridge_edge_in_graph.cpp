#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int timer; // remove initialization here

    void dfs(int node, int parent, vector<vector<int>>&adj, 
             vector<int>&vis, vector<int>&timeIn, vector<int>&low, bool &ans, int c, int d){

        vis[node] = 1;
        timeIn[node] = low[node] = timer++;

        for(int it : adj[node]){
            if(it == parent) continue;

            if(!vis[it]){
                dfs(it, node, adj, vis, timeIn, low, ans, c, d);
                low[node] = min(low[node], low[it]);

                // Check for bridge
                if(low[it] > timeIn[node]){
                    if((node == c && it == d) || (node == d && it == c))
                        ans = true;
                }
            }
            else{
                low[node] = min(low[node], timeIn[it]);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0), timeIn(V, 0), low(V, 0);
        timer = 1;  // ✅ reset timer for each test case
        bool ans = false;

        // ✅ run DFS for all components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, timeIn, low, ans, c, d);
            }
        }

        return ans;
    }
};


//ANOTHER APPROACH( MY APPROACH )
class Solution {
  public:
    int timer;
    void dfs(int node, int parent, vector<vector<int>>&bridges, vector<int>&vis, vector<int>&timeIn, vector<int>&low, vector<vector<int>>&adj){
        vis[node] = 1;
        timeIn[node] = low[node] = timer;
        timer++;
        
        for(int it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node, bridges, vis, timeIn, low , adj);
                low[node] = min(low[node], low[it]);
                
                if(low[it] > timeIn[node]){
                    bridges.push_back({it, node});
                }
            }
            else{
                low[node] = min(low[node], timeIn[it]);
            }
        }
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        int n = V;
        vector<vector<int>>adj(n);
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(n, 0);
        vector<int>timeIn(n, 0);
        vector<int>low(n, 1e9);
        
        vector<vector<int>>bridges;
        timer = 1;
        
        for(int i = 0; i < n; i++){
            if(!vis[i])
            dfs(i, -1, bridges, vis, timeIn, low, adj);
        }

        
        for(auto &it : bridges){
            if((it[0]==c && it[1]==d) || (it[0]==d && it[1]==c)) return true;
        }
        
        return false;
    }
};