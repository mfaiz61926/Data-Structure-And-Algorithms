//problem name => save your life
#include <bits/stdc++.h>   
using namespace std;
class Solution {
public:
    string maxSum(string w, char x[], int b[], int n) {
        int redefine[256];
        for(int i = 0; i < 256; i++) redefine[i] = INT_MIN;
        
        for(int i = 0; i < n; i++){
            redefine[(int)x[i]] = b[i];
        }
        
        int maxSum = INT_MIN, currSum = 0;
        int start = 0, bestStart = 0, bestEnd = 0;
        
        for(int i = 0; i < w.size(); i++) {
            int val = (redefine[(int)w[i]] != INT_MIN) ? redefine[(int)w[i]] : (int)w[i];
            
            if(currSum + val < val) {
                currSum = val;
                start = i;
            } else {
                currSum += val;
            }
            
            if(currSum > maxSum) {
                maxSum = currSum;
                bestStart = start;
                bestEnd = i;
            }
        }
        
        return w.substr(bestStart, bestEnd - bestStart + 1);
    }
};
