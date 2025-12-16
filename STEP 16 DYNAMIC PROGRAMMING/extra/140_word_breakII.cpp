class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;
    int n;

    vector<string> dfs(int idx, string &s) {
        if (memo.count(idx)) return memo[idx];

        vector<string> res;
        if (idx == n) {
            res.push_back("");
            return memo[idx] = res;
        }

        for (int l = 1; idx + l <= n; l++) {
            string word = s.substr(idx, l);
            if (dict.count(word)) {
                vector<string> next = dfs(idx + l, s);
                for (string &sentence : next) {
                    res.push_back(
                        sentence.empty() ? word : word + " " + sentence
                    );
                }
            }
        }

        return memo[idx] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for (auto &w : wordDict) dict.insert(w);
        return dfs(0, s);
    }
};

//tabulation
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<vector<string>> dp(n + 1);
        dp[n].push_back("");  // base case

        for (int i = n - 1; i >= 0; i--) {
            for (int l = 1; i + l <= n; l++) {
                string word = s.substr(i, l);
                if (dict.count(word)) {
                    for (string &tail : dp[i + l]) {
                        if (tail.empty())
                            dp[i].push_back(word);
                        else
                            dp[i].push_back(word + " " + tail);
                    }
                }
            }
        }

        return dp[0];
    }
};
