class Solution {
public:
    string s;
    int n;

    // sum range = [-135, +135] → size = 271
    long long dp[17][275][2];

    long long solve(string &P) {
        memset(dp, 0, sizeof(dp));

        // base case: at end, sum = 0 is valid
        dp[n][135][0] = 1;
        dp[n][135][1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int sum = -135; sum <= 135; sum++) {
                for (int tight = 0; tight < 2; tight++) {
                    long long ans = 0;

                    int limit = tight ? s[i] - '0' : 9;
                    for (int d = 0; d <= limit; d++) {
                        int newSum;
                        if ((i + 1) % 2)  // odd position
                            newSum = sum + d;
                        else             // even position
                            newSum = sum - d;

                        if (newSum < -135 || newSum > 135) continue;

                        ans += dp[i + 1][newSum + 135][tight && (d == limit)];
                    }

                    dp[i][sum + 135][tight] = ans;
                }
            }
        }

        return dp[0][135][1];
    }

    long long countBalanced(long long low, long long high) {
        s = to_string(high);
        n = s.size();
        long long highCnt = solve(s);

        s = to_string(low - 1);
        n = s.size();
        long long lowCnt = solve(s);

        return highCnt - lowCnt;
    }
};
