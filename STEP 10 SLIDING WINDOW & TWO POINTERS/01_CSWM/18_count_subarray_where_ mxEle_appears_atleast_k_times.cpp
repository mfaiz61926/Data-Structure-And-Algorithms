#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size();
        int mx=*max_element(nums.begin(), nums.end());
        long long r=0;
        long long cnt=0;
        long long res=0;
        long long l=0;
        while(r<n){
            if(nums[r]==mx) cnt++;
            while(cnt==k){
                if(nums[l++]==mx)--cnt;
            }
            r++;
            res+=l;
        }
        return res;
    }
};