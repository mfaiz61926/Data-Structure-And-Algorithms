class Solution {
public:
    int cntDistinct(vector<int>&v){
        int cnt = 1;
        int mx = 1;
        int n = v.size();
        for(int i = 1; i < n; i++){
            if(v[i] == v[i - 1] + 1)mx = max(mx, ++cnt);
            else cnt = 1;
        }
        return mx;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int h_cnt = cntDistinct(hBars);
        int v_cnt = cntDistinct(vBars);

        int side = 1 + min(h_cnt, v_cnt);

        return side * side;
    }
};