#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 USING MAP
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        int l = 0;
        for(int r = 0; r < n; r++){
             if(r - l > k){
                mp[nums[l]] =0;
                l++;
            }
            if(r - l <= k && mp[nums[r]] > 0){
                return true;
            }
            mp[nums[r]]++;
        }
        return false;
    }
};


// APPROACH 2 USING SET
/*
    YOUTUBE VIDEO ON THIS Qn        : https://www.youtube.com/watch?v=AyiGBwFlMb8
    Company Tags                       : Airbnb, Palantir Technologies
    Leetcode Link                      : https://leetcode.com/problems/contains-duplicate-ii/
    Using Map (without sliding window) : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Contains%20Duplicate%20II.cpp
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_set<int> st;
        
        int i = 0, j = 0;
        
        while(j < n) {
            
            //step-1
            if(abs(i-j) > k) { //abs(i-j) <= k
                st.erase(nums[i]);
                i++; //shrink
            }
            
            //past me dekha hai nums[j] ?
            if(st.find(nums[j]) != st.end()) {
                return true;
            }
            
            st.insert(nums[j]);
            j++;
            
        }
        
        return false;
        
    }
};