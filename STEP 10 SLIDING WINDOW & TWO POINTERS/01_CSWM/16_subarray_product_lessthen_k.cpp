#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,p=1,res=0;
        while(r<nums.size()){
            p*=nums[r];
            while(l<=r && p>=k){
                p/=nums[l];
                l++;
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }
};