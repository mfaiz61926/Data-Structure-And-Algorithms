typedef long long ll;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        ll orignal = 0;
        for (int i = 0; i < n; i++) {
            orignal += strategy[i] * prices[i];
        }
        int half = k / 2;
        ll change = 0;

        for (int i = 0; i < half; i++) {
            change += (0 * prices[i]) - (strategy[i] * prices[i]);
        }
        for (int i = half; i < k; i++) {
            change += (1 * prices[i]) - (strategy[i] * prices[i]);
        }

        long long maxi = change;

        for (int i = 1; i <= n - k; i++) {
            ll lefti = -(strategy[i - 1] * prices[i - 1]);
            ll midi = -prices[i + half - 1];
            ll righti =
                prices[i + k - 1] - strategy[i + k - 1] * prices[i + k - 1];

            change = change - lefti + midi + righti;

            maxi = max(maxi, change);
        }
        return orignal + max(0LL, maxi);
    }
};