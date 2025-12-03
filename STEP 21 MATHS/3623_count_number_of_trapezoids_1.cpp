#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for(auto &it : points){
            int y = it[1];
            mp[y]++;
        }
        long long prevHL = 0;
        long long res = 0;

        for(auto & it : mp){
            int cnt = it.second;
            long long HL = 1LL * cnt * (cnt - 1)/ 2;
            res += 1LL * HL * prevHL;
            prevHL += HL;
        }
        return res % MOD;
    }
};