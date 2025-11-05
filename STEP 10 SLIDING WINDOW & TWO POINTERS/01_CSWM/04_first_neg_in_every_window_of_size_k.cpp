#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int i = 0, j = 0, n = arr.size();
        queue<int> q; // stores negative numbers only
        vector<int> ans;
        
        while (j < n) {
            if (arr[j] < 0)
                q.push(arr[j]);

            if (j - i + 1 == k) {
                if (!q.empty())
                    ans.push_back(q.front());
                else
                    ans.push_back(0);

                // Slide the window
                if (!q.empty() && arr[i] == q.front())
                    q.pop(); 

                i++;
            }
            j++;
        }
        return ans;
    }
};
