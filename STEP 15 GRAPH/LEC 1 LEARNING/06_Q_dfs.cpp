//problem link
// https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTabValue=PROBLEM
// Problem statement
// Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

// E is the number of edges present in graph G.
// Note :
// The Graph may not be connected i.e there may exist multiple components in a graph.


#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], vector<int> &visited, vector<int> &ans, int node){
    visited[node]=1;
    ans.push_back(node);
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(adj,visited,ans,it);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>visited(V,0);
    vector<vector<int>>ans;
    vector<int>adj[V];

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>temp;
            dfs(adj,visited,temp,i);
            ans.push_back(temp);
        }
    }
    return ans;
}