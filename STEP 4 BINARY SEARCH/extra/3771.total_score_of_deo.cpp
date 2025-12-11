class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<int>pref(n+1, 0);
        pref[0] = damage[0];
        for(int i = 0; i <n; i++){
            pref[i+1] = pref[i] + damage[i];
        }

        long long score = 0;
    
        for(int i = 0; i < n; i++){
            int need = pref[i + 1] + requirement[i] - hp;
            int it = lower_bound(pref.begin(), pref.begin() + i + 1, need) - pref.begin();
            score += max(0, i - it + 1);
        }

        return score;
    }
};