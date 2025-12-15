class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int>st;
        int l = 0;
        int mx_res = 0;
        for(int r = 0; r < n; r++){
            st.insert(nums[r]);
            while(*st.rbegin() - *st.begin() > limit){
                st.erase(st.find(nums[l]));
                l++;
            }

            mx_res = max(mx_res, r - l + 1);
        }

        return mx_res;
    }
};