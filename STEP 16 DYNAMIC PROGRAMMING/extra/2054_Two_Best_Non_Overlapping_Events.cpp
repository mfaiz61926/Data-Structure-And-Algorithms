#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[100001][2];
    vector<int> starts;

    int solve(int i, int taken, vector<vector<int>>& events) {
        int n = events.size();
        if (i >= n || taken == 2) return 0;

        if (dp[i][taken] != -1) return dp[i][taken];

        // skip current event
        int nt = solve(i + 1, taken, events);

        // take current event → jump to next non-overlapping
        int next = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();
        int tk = events[i][2] + solve(next, taken + 1, events);

        return dp[i][taken] = max(tk, nt);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        memset(dp, -1, sizeof(dp));

        int n = events.size();
        starts.resize(n);
        for (int i = 0; i < n; i++) {
            starts[i] = events[i][0];
        }

        return solve(0, 0, events);
    }
};
