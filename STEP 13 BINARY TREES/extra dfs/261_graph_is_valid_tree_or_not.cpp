#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node] = 1;
        for(auto & it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        if(m != n-1) return 0;
        vector<int>adjj[n];
        
        for(auto & i : adj){
            adjj[i[0]].push_back(i[1]);
            adjj[i[1]].push_back(i[0]);
            
        }
        
        vector<int>vis(n, 0);
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjj, vis);
            }
        }
        
        return cnt == 1;
        
    }
};
