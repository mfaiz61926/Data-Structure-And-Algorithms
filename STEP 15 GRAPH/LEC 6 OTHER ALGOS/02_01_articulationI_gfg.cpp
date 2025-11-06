// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    int timer =1;
  
    void dfs(int node, int parent, vector<int>adj[], vector<int>&vis, vector<int>&mark, vector<int>&low, vector<int>&timeIn){
        vis[node] = 1;
        low[node] = timeIn[node] = timer++;
        
        int child = 0;
        for(auto & it: adj[node]){
            if(it == parent)continue;
            
            if(!vis[it]){
                dfs(it, node, adj, vis, mark, low , timeIn);
                low[node] = min(low[node], low[it]);
                
                if(low[it] >= timeIn[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], timeIn[it]);
            }
        }
        
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        // vector<vector<int>>adj(V);
        int n = V;
        
        vector<int>vis(n,0), timeIn(n,0), low(n,0);
        vector<int>mark(n, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, mark, low , timeIn);
            }
        }
        
        vector<int>ans;
        
        for(int i = 0; i < n; i++){
            if(mark[i] == 1) ans.push_back(i);
        }
        
        if(ans.size()==0) return {-1};
        return  ans;
        
    }
};