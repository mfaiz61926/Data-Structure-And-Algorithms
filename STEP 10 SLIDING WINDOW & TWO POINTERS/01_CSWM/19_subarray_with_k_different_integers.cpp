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



//Approach-2 (One Pass Flow)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        int i_chota  = 0;
        int j        = 0;
        int i_bada   = 0;
        
        int result   = 0;
  
        while(j < n) {
            mp[nums[j]]++;
            
            while(mp.size() > k) {
                mp[nums[i_chota]]--;
                if(mp[nums[i_chota]] == 0) {
                    mp.erase(nums[i_chota]);
                }
                i_chota++;
                i_bada = i_chota;
            }
            
            while(mp[nums[i_chota]] > 1) {
                mp[nums[i_chota]]--;
                i_chota++;
            }
            
            if(mp.size() == k) {
                result += i_chota - i_bada + 1;
            }
            j++;
        }
        
        return result;
    }
};