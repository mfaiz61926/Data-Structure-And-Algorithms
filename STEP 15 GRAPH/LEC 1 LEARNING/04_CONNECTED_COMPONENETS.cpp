//leadcode premium  ******
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[],bool *vis,int src){
    vis[src]=true;
    for(auto&i:adj[src]){
        if(!vis[i]){

            dfs(adj,vis,i);
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int>adj[v+1];
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt=0;
    bool vis[v+1];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<v;i++){
        if(!vis[i]){
            cnt++;
            dfs(adj,vis,i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}