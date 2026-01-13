// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int n = nums.size();
//         map<int,int>mp;
//         for(auto & i : nums) mp[i]++;

//         int cnt = 0;
//         for(auto & i : mp){
//             int x = i.second;
//             if(x == 1) return -1;
//             cnt += x/3;
//             if(x % 3 != 0) cnt++;
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    vector<int>dp;
    int coinchange(int n){
        if(n == 2 || n == 3) return 1;
        if(n == 1) return 100005;
        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        if(n >= 2){
            ans = min(ans, coinchange(n-2) + 1);
        }
        if(n >= 3){
            ans = min(ans, coinchange(n - 3) + 1);
        }

        return dp[n] = ans;
    }
    int minOperations(vector<int>& nums) {
        dp.resize(100005, -1);
        int n = nums.size();
        map<int,int>mp;
        for(auto & i : nums) mp[i]++;

        vector<int>arr;
        for(auto & i : mp) arr.push_back(i.second);

        int cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            int x = coinchange(arr[i]);
            if(x >= 100005) return -1;
            cnt += x;
        }

        return cnt;
    }
};