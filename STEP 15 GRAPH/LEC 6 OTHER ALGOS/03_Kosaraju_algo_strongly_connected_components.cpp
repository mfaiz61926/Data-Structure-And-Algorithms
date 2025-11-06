#include <bits/stdc++.h>
using namespace std;


//KOSARAJU'S ALGO FOR STRONGLY CONNECTED COMPONENTS.

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};


//GFG ONE -> STRONGLY CONNECTED COMPONENTS
//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(vector<vector<int>>&adj, int node, vector<int>&vis, stack<int>&st){
        vis[node] = 1;
        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(adj, it, vis, st);
            }
        }
        st.push(node);
    }
    
    
    void dfs2(vector<vector<int>>&adjT, vector<int>&vis, int node){
        vis[node] = 1;
        for(auto & it : adjT[node]){
            if(!vis[it]){
                dfs2(adjT, vis, it);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        stack<int>st;
        vector<int>vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, i, vis, st);
            }
        }
        
        vector<vector<int>>adjT(n);
        
        for(int i = 0; i < n; i++){
            vis[i] = 0;
            for(auto &it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        
        int cnt = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                cnt++;
                dfs2(adjT, vis, node);
            }
        }
        
        return cnt;
    }
};