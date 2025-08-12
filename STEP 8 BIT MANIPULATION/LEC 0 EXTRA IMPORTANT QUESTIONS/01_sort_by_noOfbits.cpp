
// 1356. Sort Integers by The Number of 1 Bits
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int noOfsetBits(int n){
        int ans = 0;
        while (n > 0) {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }

    static bool compare (int a, int b) {
        int setbitA = noOfsetBits(a);
        int setbitB = noOfsetBits(b);
        if(setbitA == setbitB) {
            return a < b;
        }
        return setbitA < setbitB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};