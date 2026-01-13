class Solution {
public:
    int countHousePlacements(int n) {
        if(n == 0) return 1;
        if(n == 1) return 4;
        int a = 1;
        int b = 2;
        long long x = 0;
        long long MOD = 1e9 + 7;
        for(int i = 2; i <= n; i++){
            int cur = b + a;
            a = b %MOD;
            b = cur %MOD;
            x = (1LL * cur * cur) % MOD;
        }
        return x;
    }
};