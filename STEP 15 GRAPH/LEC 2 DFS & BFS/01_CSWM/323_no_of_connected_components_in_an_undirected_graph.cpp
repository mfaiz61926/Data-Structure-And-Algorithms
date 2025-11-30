#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node, vector<int>adj[], int vis[], vector<int>&temp){
        
        vis[node]=1;
        temp.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]){
                
                dfs(it,adj,vis,temp);
            }
        }
       
    }  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>ans;
        int n=edges.size();
        
        vector<int>adj[V];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int>temp;
                dfs(i,adj,vis,temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};