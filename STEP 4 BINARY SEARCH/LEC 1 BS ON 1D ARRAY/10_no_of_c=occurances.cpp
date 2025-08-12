#include <bits/stdc++.h>
using namespace std;
//Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. gfg
class Solution {
    public:
    
      int firstO(vector<int>&arr,int x){
          int n=arr.size();
          int low=0;int high=n-1;
          int ans=-1;
          while(low<=high){
              int mid=low+(high-low)/2;
              if(arr[mid]==x){
                  ans=mid;
                  high=mid-1;
              }
              else if(arr[mid]>x){
                  high=mid-1;
              }else{
                  low=mid+1;
              }
          }
          return ans;
      }
      
      int lastO(vector<int>&arr,int x){
          int n=arr.size();
          int low=0;
          int high=n-1;
          int ans=-1;
          while(low<=high){
              int mid=low+(high-low)/2;
              if(arr[mid]==x){
                  ans=mid;
                  low=mid+1;
              }
              else if(arr[mid]>x){
                  high=mid-1;
              }else{
                  low=mid+1;
              }
          }
          return ans;
      }
      int countFreq(vector<int>& arr, int target) {
          // code here
          int fo=firstO(arr,target);
          int lo=lastO(arr,target);
          if(lo==-1 && fo==-1)return 0;
          return (lo-fo+1);
      }
  };