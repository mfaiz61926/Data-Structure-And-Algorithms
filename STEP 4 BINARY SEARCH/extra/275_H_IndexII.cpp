#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = citations.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(citations[mid] == n - mid){
                return citations[mid];
            }
            else if(citations[mid] < n - mid){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return n - low;
    }
};