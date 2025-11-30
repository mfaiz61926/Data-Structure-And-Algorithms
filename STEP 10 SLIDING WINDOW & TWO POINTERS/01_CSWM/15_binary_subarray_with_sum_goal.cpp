#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(vector<int>&nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int l = 0;
        int cnt = 0;
        int sum = 0;
        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt = cnt + r - l + 1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal) - f(nums, goal - 1);
    }
};