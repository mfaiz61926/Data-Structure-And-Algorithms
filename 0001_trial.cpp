/******************************************************************************

                              بسم الله الرحمان الرحيم
Author:mfaiz_1

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define int            long long int
int MOD=1e9+7; 
const int N = 100005;

vector<int>adj[N];
vector<vector<int>>scc;
int tin[N], low[N], val[N];
bool inStack[N];
stack<int>st;
int timer;

void dfs(int u){
    tin[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for(int v : adj[u]){
        if(!tin[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v]){
            low[u] = min(low[u], tin[v]);
        }
    }

    if(low[u] == tin[u]){
        int v = -1;
        scc.push_back({});
        while(v != u){
            v = st.top();
            st.pop();
            scc.back().push_back(val[v]);
            inStack[v] = false;
        }
    }
}

void solve() {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> val[i];
        }
        int m; cin >> m;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for(int u = 1; u <= n; u++){
            if(!tin[u]){
                dfs(u);
            }
        }

        int mnV = 0;
        int ways = 1;

        for(auto & i : scc){
            // cout << i;
            int mn = *min_element(i.begin(), i.end());
            mnV += mn;
            int cnt = 0;
            for(auto it : i){
                if(it == mn) cnt++;
            }
            ways = (ways * cnt) % MOD;
        }

        cout << mnV << " " << ways % MOD << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}