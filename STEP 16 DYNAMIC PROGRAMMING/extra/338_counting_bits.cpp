class Solution {
public:
    int cnt_bit(int n){
        int cnt = 0;
        while(n){
            cnt += n&1;
            n/=2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i =0; i <=n; i++){
            ans.push_back(cnt_bit(i));
        }
        return ans;
    }
};