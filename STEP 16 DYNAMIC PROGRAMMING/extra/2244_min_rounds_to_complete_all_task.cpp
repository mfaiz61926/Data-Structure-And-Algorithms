// class Solution { my sol
// public:
//     int minimumRounds(vector<int>& tasks) {
//         int n = tasks.size();
//         map<int,int>mp;
//         for(auto &i : tasks){
//             mp[i]++;
//         }

//         int cnt = 0;

//         for(auto & i: mp){
//             int x = i.second;
//             if(x == 1) return -1;
//             cnt += x/3;
//             if(x % 3 != 0) cnt++; 
//         }
//         return cnt;
//     }
// };


class Solution {//dp
public:
vector<int>dp;
    int coinchange(int n){

        if(n==2 || n==3)return 1;

        //if(n<0)return 100005;

        if(n==1){
            return 100005;
        }

        if(dp[n]!=-1)return dp[n];

        int a=INT_MAX;
        if(n>=2){
            a= min(a, coinchange(n-2)+1);
        }

        if(n>=3){
            a= min(a, coinchange(n-3)+1);
        }

        return dp[n]= a;
        
    }
    int minimumRounds(vector<int>& tasks) {
        dp.resize(100005, -1);

        unordered_map<int, int>mp;
        for(auto i: tasks)mp[i]++;

        vector<int>arr;
        for(auto k: mp){
            arr.push_back(k.second);
        }

        int ans=0;
        for(int i=0; i<arr.size(); i++){
            int curr= coinchange(arr[i]);
            if(curr>=100005)return -1;
            else ans+=curr;
        }

        return ans;
    }
};