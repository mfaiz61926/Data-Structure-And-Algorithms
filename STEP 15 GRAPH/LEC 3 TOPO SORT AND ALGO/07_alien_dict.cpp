#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int>topoSort(vector<vector<int>>&adj, unordered_set<char>&uniq_char){
        vector<int>indegree(26, 0);
        
        for(int u = 0; u < 26; u++){
            for(auto &v : adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int>q;
        
        for(char ch : uniq_char){
            if(indegree[ch-'a'] == 0){
                q.push(ch-'a');
            }
        }
        
        vector<int>topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto &it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        unordered_set<char>uniq_char;
        vector<vector<int>>adj(26);
        
        for(auto & word : words){
            for(auto &ch : word){
                uniq_char.insert(ch);
            }
        }
        
        
        for(int i = 0; i < n - 1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            
            int len = min(w1.size(), w2.size());
            
            bool found = false;
            
            for(int j = 0; j < len; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]-'a'].push_back(w2[j] - 'a');
                    found = true;
                    break;
                }
            }
            
            if(!found && w1.size() > w2.size()) return "";
        }
        
        vector<int>topo = topoSort(adj, uniq_char);
        if(topo.size() != uniq_char.size()) return "";
        
        string ans = "";
        for(auto &i : topo){
            ans += (char)(i+'a');
        }
        
        return ans;
    }
};