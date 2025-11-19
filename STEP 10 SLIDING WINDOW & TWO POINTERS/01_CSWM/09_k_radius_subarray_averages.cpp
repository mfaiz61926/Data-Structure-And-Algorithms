#include <bits/stdc++.h>
using namespace std;


//MY PREFIXSUM APPROACH
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        int n = nums.size();
        vector<long long>pref(n,0);
        pref[0] = nums[0];
        for(int i = 1;i < n; i++){
            pref[i] = nums[i] + pref[i - 1];
        }

        vector<int>ans(n);
        for(int i = 0;i < n; i++){
            if(i-k >=0 && i + k < n){
                int x = i+k - i + k + 1;
                
                long long sum = pref[i+k];
                if(i-k >0)sum-=pref[i-k-1];
                ans[i] = sum/x;
            }
            else ans[i] = -1;
        }

        return ans;
    }
};

/*
      YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=M_YXCATc4ro
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/k-radius-subarray-averages/
*/

//My Approach-2 using Prefix Array is in Array/Cumulative_Sum(Prefix Array) folder Folde. Link below - 
//Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Cumulative_Sum(Prefix%20Array)/K%20Radius%20Subarray%20Averages.cpp


//Approach-1 : Using Sliding Window
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k == 0)
            return nums;
    
        vector<int> result(n, -1);
        
        if(n < 2*k + 1)
            return result;
        
        long long windowSum = 0;
        
        int left  = 0;
        int right = 2*k;
        int i     = k;
        
        for(int i = left; i <= right; i++) {
            windowSum += nums[i];
        }
        
        
        result[i] = windowSum/(2*k+1);
        
        i++;
        right++; //Shifting window
        
        while(right < n) {
            
            int out_of_window  = nums[left];
            int came_to_window = nums[right];
            
            windowSum = windowSum - out_of_window + came_to_window;
            
            result[i] = windowSum/(2*k+1);
            i++;
            left++;
            right++;
            
        }
        return result;
    }
};