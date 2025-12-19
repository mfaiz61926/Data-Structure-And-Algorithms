#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void reset(int x){
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
        return a[2] < b[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DisjointSet ds(n);

        sort(meetings.begin(), meetings.end(), comp);

        ds.unionByRank(0, firstPerson);
        int i =0;
        int m = meetings.size();
        while(i < m){
            int time = meetings[i][2];
            vector<int>list;
            while(i < m && meetings[i][2] == time){
                ds.unionByRank(meetings[i][0], meetings[i][1]);
                list.push_back(meetings[i][0]);
                list.push_back(meetings[i][1]);
                i++;
            }
            for(auto &it : list){
                if(ds.findUPar(0) != ds.findUPar(it)){
                    ds.reset(it);
                }
            }
        }

        vector<int>ans;

        for(int i = 0; i < n; i++){
            if(ds.findUPar(0) == ds.findUPar(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};