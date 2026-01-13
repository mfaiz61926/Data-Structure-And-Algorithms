class Solution {
public:

    const int MOD = 1e9 + 7;
    map<pair<int,int>, int>mp;
    int solve(int s, int e, int k){
        if (abs(e - s) > k) return 0;
        if ((k - abs(e - s)) % 2 != 0) return 0;

        if(k == 0) return s == e;
        pair<int,int> key = {s,k};

        if(mp.count(key)) return mp[key];
        int tk = solve(s+1, e, k-1);
        int nt = solve(s-1, e, k-1);

        return mp[key] = (tk + nt) % MOD;
    }
    int numberOfWays(int s, int e, int k) {
        mp.clear();
        return solve(s,e,k);
    }
};