// gfg http://geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxConsecutiveOnes(int n) {
        // code here
        int mx = 0;
        int c = 0;
        while(n > 0) {
            int b = (n&1);
            if(b){
                c++;
            }else{
                c=0;
            }
            mx = max(mx, c);
            n = n >> 1;
        }
        return mx;
        
    }
};
