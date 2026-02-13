class Solution {
public:
    int dfs(int node, vector<vector<int>>&adj, vector<int>&vis){
        vis[node] = 1;
        int cnt = 1;
        for(auto & it : adj[node]){
            if(!vis[it]){
                cnt += dfs(it, adj, vis);
            }
        }

        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int m = bombs[0].size();

        int mx = 1;
        vector<vector<int>>adj(n);

        for(int i = 0; i < n; i++){
            auto t = bombs[i];
            int x1 = t[0];
            int y1 = t[1];
            int r1 = t[2];
            int cnt = 1;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                auto it = bombs[j];
                int x2 = it[0];
                int y2 = it[1];
                int r2 = it[2];

                long long  dx = x1 - x2, dy = y1 - y2;
                long long dis = dx * dx + dy * dy;

                if(dis <= 1LL * r1 * r1) adj[i].push_back(j);
            }
        }

        for(int i = 0; i < n; i++){
            vector<int>vis(n, 0);
            mx = max(mx, dfs(i, adj, vis));
        }

        return mx;
        
    }
};