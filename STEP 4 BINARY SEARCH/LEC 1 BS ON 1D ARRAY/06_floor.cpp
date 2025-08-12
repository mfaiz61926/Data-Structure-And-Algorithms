#include<bits/stdc++.h>
using namespace std;

//Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equal to x. This element is called the floor of x. If such an element does not exist, return -1.

class Solution {
    public:
  
      int findFloor(vector<int>& arr, int x) {
          // Your code here
          int lo=0;
          int ans=-1;
          int hi=arr.size()-1;
          while(lo<=hi){
              int mid=lo+(hi-lo)/2;
              if(arr[mid]<=x){
                  ans=mid;
                  lo=mid+1;
              }else{
                  hi=mid-1;
              }
          }
          return ans;
          
      }
  };
  