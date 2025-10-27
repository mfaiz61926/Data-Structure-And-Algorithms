#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //logic is to keep tracking prev and curr
        priority_queue<int>curr_pq, prev_pq;
        int n = nums.size();
        for(int i = 0 ; i < k; i++) curr_pq.push(nums[i]);
        vector<int>ans;
        ans.push_back(curr_pq.top());

        for(int i = k; i < n; i++){
            int removeElement = nums[i - k];
            prev_pq.push(removeElement);
            curr_pq.push(nums[i]);

            while(!prev_pq.empty() && prev_pq.top() == curr_pq.top()){
                prev_pq.pop();
                curr_pq.pop();
            }

            ans.push_back(curr_pq.top());
        }
        return ans;
    }
};