#include <bits/stdc++.h>
using namespace std;

//leetcode 34. Find First and Last Position of Element in Sorted Array
//link  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
    public:
        int firstO(vector<int>& arr, int target) {
              // code here
              int n=arr.size();
              int low=0;
              int high=n-1;
              int ans=-1;
              while(low<=high){
                  int mid=low+(high-low)/2;
                  if(arr[mid]==target){
                      ans=mid;
                      high=mid-1;
                  }
                  else if(arr[mid]>target){
                    high=mid-1;
                  }
                  else{
                      low=mid+1;
                  }
              }
              return ans;
          }
    
          
    int lastO(vector<int> &arr, int x) {
        int n=arr.size();
        int low = 0, high = n - 1;
        int ans = -1;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == x) {
                ans = mid;
                //look for smaller index on the left
                low = mid + 1;
            }
            else if(arr[mid]>x){
                high=mid-1;
            }
            else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
        //main func
        vector<int> searchRange(vector<int>& nums, int target) {
            int n=nums.size();
            int lob=firstO(nums,target);
            int uob=lastO(nums,target);
            return{lob,uob};
        }
    };