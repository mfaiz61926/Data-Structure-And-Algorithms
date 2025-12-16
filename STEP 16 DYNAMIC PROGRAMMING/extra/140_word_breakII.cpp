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
