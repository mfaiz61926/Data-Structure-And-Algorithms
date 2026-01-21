class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }
            int found = 0;
            for(int j = 0; j < 32; j++){
                if((nums[i] & (1 << j)) > 0) continue;

                int prev = j - 1;
                
                int mask = nums[i] ^ (1 <<  prev);
                ans.push_back(mask);
                found = 1;
                break;
            }
        }
        return ans;
    }
};