class Solution {
public:
    using ll = long long;
    string sourcestr;
    string targetstr;

    typedef pair<ll, string> p;

    vector<ll>dp;
    ll MXN = 1e10;
    unordered_map<string, vector<pair<string, ll>>> adj;
    set<ll> st;

    unordered_map<string, unordered_map<string, ll>> dijkstraDP;

    ll dijkstra(string &start, string& end){

        if(dijkstraDP[start].count(end)){
            return dijkstraDP[start][end];
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        unordered_map<string, ll>result;

        result[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            ll dis = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if(node == end) {
                break;
            }

            for(auto & it : adj[node]){
                string adjNode = it.first;
                ll w = it.second;

                if(!result.count(adjNode) || dis + w < result[adjNode]){
                    result[adjNode] = dis + w;
                    pq.push({dis + w, adjNode});
                }
            }
        }
        ll finalcost = result.count(end) ? result[end] : MXN;
        
        return dijkstraDP[start][end] = finalcost;
    }

    ll solve(int idx){
        if(idx >= sourcestr.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        ll minCost = MXN;

        if(sourcestr[idx] == targetstr[idx]){
            minCost = solve(idx + 1);
        }

        for(auto &len : st){
            if(idx + len > sourcestr.size()){
                break;
            }

            string srcSub = sourcestr.substr(idx, len);
            string tarSub = targetstr.substr(idx, len);

            if(!adj.count(srcSub)) continue;

            ll min_path_cost = dijkstra(srcSub, tarSub);

            if(min_path_cost == MXN){
                continue;
            }

            minCost = min(minCost, min_path_cost + solve(idx + len));
        }

        return dp[idx] = minCost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        sourcestr = source;
        targetstr = target;

        dp.assign(10001, -1);
        for(int i = 0; i < original.size(); i++){
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        for(auto & i : original){
            st.insert(i.length());
        }

        ll res = solve(0);

        return res == MXN ? -1 : res;

    }
};