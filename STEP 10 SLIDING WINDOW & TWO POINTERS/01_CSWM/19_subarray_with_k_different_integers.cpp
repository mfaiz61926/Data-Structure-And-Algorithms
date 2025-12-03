#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>&nums, int k){
        int n = nums.size();
        int l = 0; 
        int cnt = 0;
        map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt = cnt + i - l + 1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};