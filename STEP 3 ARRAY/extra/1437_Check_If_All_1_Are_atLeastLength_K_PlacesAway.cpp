#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        for(int i = 0; i < n; i++){
            if(nums[i]==1 && prev == -1){
                prev = i;
                continue;
            }
            if(nums[i] == 1){
                int diff = i - prev-1;
                if(diff<k)return false;
                else{
                    prev = i;
                }
            }
        }
        return true;
    }
};