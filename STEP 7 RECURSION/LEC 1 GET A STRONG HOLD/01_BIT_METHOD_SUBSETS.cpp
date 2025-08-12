// m1 backtracking: t=2^n; s=n*2^n ; auxilary space ---> stack size = o(n)  recursion call = o(n;)
#include <bits/stdc++.h>
using namespace std;
void bkt(int st, vector<int>& arr,vector<int>&v1, vector<vector<int>>&v){
        v.push_back(v1);
        
        for(int i=st; i<arr.size(); i++){
            v1.push_back(arr[i]);
            bkt(i+1,arr,v1,v);
            v1.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>v;
        vector<int>v1;
        bkt(0,arr,v1,v);
        return v;
    }
// ------------------------------------------------------------------------------------------------------------------------------------------------------------
// m2: bitMasking: t=n*2^n; s=n*2^n; auxS=n;
vector<vector<int>>solve(vector<int>&arr){
 vector<vector<int>>v;
        
        for(int msk=0; msk<(1<<arr.size()); msk++){
            vector<int>ss;
            for(int i=0;i<arr.size(); i++){
                if(msk&(1<<i)){
                    ss.push_back(arr[i]);
                }
            }
            v.push_back(ss);
        }
        
        sort(v.begin(), v.end());
        return v;
}
// ---------------------------------------------------------------================================================
// m3: iterattive; same complexity;
// User function Template for C++

class Solution {
  public:
 static  bool cmp(vector<int>&a, vector<int>&b){
       int n=min(a.size(),b.size());
       
       for(int i=0;i<n;i++){
           if(a[i]!=b[i]){
               return a[i]<b[i];
           }
           
       }
       return a.size()<b.size();
   }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
         sort(arr.begin(),arr.end());
      vector<vector<int>>ps = {{}};
     
      
      for(int x: arr){
          int m=ps.size();
          for(int i=0; i<m;i++){
              vector<int>s=ps[i];
              s.push_back(x);
              ps.push_back(s);
          }
      }
      sort(ps.begin(),ps.end(), cmp);
      return ps;
    }
};