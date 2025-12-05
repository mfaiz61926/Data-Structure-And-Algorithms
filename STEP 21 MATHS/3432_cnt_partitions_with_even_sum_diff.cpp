class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(),0);
        int cnt = 0;
        int cur_sum = 0;
        for(int i = 0; i < n - 1; i++){
            cur_sum += nums[i];
            if((cur_sum - (tot_sum - cur_sum))%2==0) cnt++;
        }
        return cnt;
    }
};