#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int len = 0;
        map<int,int>mp;
        for(int r = 0; r < n; r++){
            mp[nums[r]]++;
            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }
            len = max(len, r - l + 1);
        }

        return len;
    }
};