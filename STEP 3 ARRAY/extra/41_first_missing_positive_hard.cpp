#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool onePresent = false;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1) onePresent = true;
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        if(!onePresent) return 1;
        
        for(int i = 0; i < n; i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) continue;

            nums[idx] *= -1;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};