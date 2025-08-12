#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int vis[],stack<int>&st,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
    // Your code hereint
    int v=adj.size();
    int vis[v]={0};
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
//topo sort algo
}