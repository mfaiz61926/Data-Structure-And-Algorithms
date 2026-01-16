class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(m);
        hFences.push_back(1);

        vFences.push_back(n);
        vFences.push_back(1);

        unordered_set<int>st1, st2;

        for(int i = 0; i < hFences.size(); i++){
            for(int j = i + 1; j < hFences.size(); j++){
                int diff = abs(hFences[i] - hFences[j]);
                st1.insert(diff);
            }
        }

        for(int i = 0; i < vFences.size(); i++){
            for(int j = i + 1; j < vFences.size(); j++){
                int diff = abs(vFences[i] - vFences[j]);
                st2.insert(diff);
            }
        }

        int mx = -1;
        for(auto & i: st1){
            if(st2.find(i)!=st2.end()) mx = max(mx, i);
        }

        return (mx == -1) ? -1 : (1LL * mx * mx ) % MOD;

    }
};