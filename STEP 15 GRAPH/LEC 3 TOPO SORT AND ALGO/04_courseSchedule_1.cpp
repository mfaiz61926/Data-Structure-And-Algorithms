#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int v = numCourses;
            vector<vector<int>> adj(v);  // Use vector of vectors
    
            for (auto& it : prerequisites) {
                adj[it[0]].push_back(it[1]);
            }
    
            vector<int> indegree(v, 0);  // Corrected indegree array initialization
            for (int i = 0; i < v; i++) {
                for (auto& it : adj[i]) {
                    indegree[it]++;
                }
            }
    
            queue<int> q;
            for (int i = 0; i < v; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
    
            int count = 0;  // Track number of processed nodes
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                count++;
    
                for (auto& it : adj[node]) {
                    indegree[it]--;
                    if (indegree[it] == 0) {
                        q.push(it);
                    }
                }
            }
    
            return count == v;
        }
    };
    