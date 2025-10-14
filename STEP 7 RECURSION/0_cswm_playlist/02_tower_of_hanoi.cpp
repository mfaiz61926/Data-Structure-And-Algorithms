#include <bits/stdc++.h>
using namespace std;
//gfg
class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        if(n==0){
            return 0;
        }
        
       int  cnt = towerOfHanoi(n-1, from, aux , to);
       
        cnt++;
        
        cnt += towerOfHanoi(n-1,aux ,to , from);
        
        return cnt;
        
    }
};