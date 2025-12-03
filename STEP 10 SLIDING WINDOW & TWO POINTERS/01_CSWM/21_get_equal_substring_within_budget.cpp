#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int l = 0;
        int res = 0;
        int c = 0;
        for(int j = 0; j < n; j++){
            c+=abs(s[j] - t[j]);
            while(c > maxCost){
                c-=abs(s[l] - t[l]);
                l++;
            }
            res = max(res, j - l + 1);
        }
        return res;
    }
};