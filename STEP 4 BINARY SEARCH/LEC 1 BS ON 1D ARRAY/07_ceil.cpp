#include <bits/stdc++.h>
using namespace std;

//Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x. This element is called the ceil of x. If such an element does not exist, return -1.

class Solution {
    public:
      int findCeil(vector<int>& arr, int x) {
          // code here
          int n=arr.size();
          int low=0;
          int high=n-1;
          int ans=-1;
          while(low<=high){
              int mid=low+(high-low)/2;
              if(arr[mid]>=x){
                  ans=mid;
                  high=mid-1;
              }else{
                  low=mid+1;
              }
          }
          return ans;
          
      }
  };