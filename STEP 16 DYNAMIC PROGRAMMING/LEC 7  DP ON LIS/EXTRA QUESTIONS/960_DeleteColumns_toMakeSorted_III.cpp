class Solution { //USING LIS
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int lis = 1;
        vector<int>dp(m,1);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < i; j++){
                bool ok = true;
                for(int r = 0; r < n; r++){
                    if(strs[r][i] < strs[r][j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    dp[i] = max(dp[i], dp[j] + 1);
                    lis = max(lis, dp[i]);
                }
            }
        }
        return m - lis;
    }
};

class Solution { // USING TOPO-SORT
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<int>ind(m, 0);
        vector<int>dist(m, 1);

        vector<vector<int>>adj(m);

        for(int i = 0; i < m; i++){
            for(int j = i+1; j < m; j++){
                bool ok = true;
                for(int r = 0; r < n; r++){
                    if(strs[r][i] > strs[r][j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    adj[i].push_back(j);
                    ind[j]++;
                }
            }
        }

        queue<int>q;
        for(int i = 0; i < m; i++){
            if(ind[i] == 0)q.push(i);
        }

        int longest = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &it : adj[node]){
                dist[it] = max(dist[it], dist[node]+1);
                longest = max(longest, dist[it]);
                if(--ind[it] == 0)q.push(it);
            }
        }

        return m - longest;
    }
};