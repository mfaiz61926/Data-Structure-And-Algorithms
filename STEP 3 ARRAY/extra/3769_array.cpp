class Solution {
public:
    int f(int n){
        string s = "";
        while(n){
            s += to_string(n%2);
            n/=2;
        }
        int num = 0;
        for(int i = s.size()-1; i >= 0;i--){
            num = num + (s[i]-'0') * pow(2,s.size() - i);
        }
        cout << num <<" ";
        return num;
        

    }
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<pair<int,int>>temp;
        for(int i = 0; i < n; i++){
            temp.push_back({f(nums[i]), nums[i]});
        }

        sort(temp.begin(), temp.end());
        for(auto &it : temp){
            ans.push_back(it.second);
        }
        return ans;
    }
};