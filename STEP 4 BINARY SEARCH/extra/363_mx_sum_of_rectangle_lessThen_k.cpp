#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();     //rows
        int m = matrix[0].size();  //columns

        int res = INT_MIN;

        for(int i = 0; i < m; i++){
            vector<int>sums(n);
            for(int j = i; j < m ; j++){
                for(int r = 0; r < n; r++){
                    sums[r] += matrix[r][j];
                } 
                // now just calcute the the subarray with mx sum <= k
                set<int>s = {0};
                int run_sum = 0;
                for(int sum : sums){
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if(it != s.end()){
                        res = max(res, run_sum - *it);
                    }
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};