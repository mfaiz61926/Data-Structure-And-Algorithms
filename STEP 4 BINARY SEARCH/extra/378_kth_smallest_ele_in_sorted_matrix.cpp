#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         priority_queue<int>pq;
//         for(int i = 0;i < n; i++){
//             for(int j = 0; j < m ; j++){
//                 if(pq.size() <k)
//                 pq.push(matrix[i][j]);
//                 else{
//                     if(pq.top()>matrix[i][j]){
//                         pq.pop();
//                         pq.push(matrix[i][j]);
//                     }
//                 }
//             }
//         }

//         return pq.top();
//     }
// };


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];

        while(low <= high){
            int cnt = 0;
            int mid = low + (high - low )/2;

            for(int i = 0; i < n; i++){
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if(cnt < k) low = mid + 1;
            else high = mid - 1;

        }
        return low;
    }
};