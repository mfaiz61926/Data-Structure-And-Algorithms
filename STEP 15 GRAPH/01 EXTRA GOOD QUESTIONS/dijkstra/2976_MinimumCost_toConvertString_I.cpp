class Solution {
public: //DIJKSTRA
    void dijkstra(int src, vector<vector<pair<int,int>>>&adj, vector<int>&dist){
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;

            pq.pop();

            // if(dis > dist[node]) continue;
            for(auto & it : adj[node]){
                int v = it.first;
                int w = it.second;

                if(dis + w < dist[v]){
                    dist[v] = dis + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
}

    //floyd warshalllll...
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source.size() != target.size()) return -1;
        
        vector<vector<int>>dist(26, vector<int>(26, INT_MAX));

        for(int i = 0; i < original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];

            dist[u][v] = min(dist[u][v] , cost[i]);
        }
        //floyd warshalllll....
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dist[i][k] < INT_MAX && dist[k][j] < INT_MAX){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long ans = 0;
        for(int  i = 0; i < source.size(); i++){
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(u == v) continue;
            if(dist[u][v] >= INT_MAX) return -1;
            ans += dist[u][v];
        }

        return ans;
    }
};