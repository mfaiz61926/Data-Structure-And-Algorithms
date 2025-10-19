#include <bits/stdc++.h>
using namespace std;
// ITS THE GFG ONE QUESTION HERE STRICTLY INCREASEING AND STRICTLY DECREASING IS NOT COUNTED.
// two types 
// 1 i solved it  

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        // code here
    vector<int>dp1(n, 1);
	vector<int>dp2(n, 1);

	//Lis in forward direction
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i]){
				if(dp1[i] < dp1[j] + 1){
					dp1[i] = dp1[j] + 1;
				}
			}
		}
	}
	//Lis in backword direction
	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j >= i; j--){
			if(arr[j] < arr[i]){
				if(dp2[i] < dp2[j] + 1){
					dp2[i] = dp2[j] + 1;
				}
			}
		}

	}
	int mx = 0;
	for(int i = 0; i < n; i++){
	    if(dp1[i] == 1) dp1[i] = 0 , dp2[i] = 0;
	    if(dp2[i] == 1) dp2[i] =0, dp1[i] = 0;;
		mx = max(mx, dp1[i] + dp2[i] - 1);
	}

	return mx;
        
    }
};

// striver solved it ->
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n, 1);
        vector<int>dp2(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int p = 0; p < i; p++){
                if(nums[i] > nums[p]){
                    dp1[i] = max(dp1[i] , 1 + dp1[p]);
                }
            }
        }
        
        for(int i = n - 1; i >= 0; i--){
            for(int p = n - 1; p > i; p--){
                if(nums[i] > nums[p]){
                    dp2[i] = max(dp2[i] , 1 + dp2[p]);
                }
            }
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            int v = dp1[i] + dp2[i] - 1;
            if(v != dp1[i] && v != dp2[i]){
                mx = max(mx, v);
            }
        }
        return mx;
        
        
    }
};


//this is the original form sheet its on ninjas coding
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// Write your code here.
	vector<int>dp1(n, 1);
	vector<int>dp2(n, 1);

	//Lis in forward direction
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i]){
				if(dp1[i] < dp1[j] + 1){
					dp1[i] = dp1[j] + 1;
				}
			}
		}
	}
	//Lis in backword direction
	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j >= i; j--){
			if(arr[j] < arr[i]){
				if(dp2[i] < dp2[j] + 1){
					dp2[i] = dp2[j] + 1;
				}
			}
		}

	}
	int mx = 0;
	for(int i = 0; i < n; i++){
		mx = max(mx, dp1[i] + dp2[i] - 1);
	}

	return mx;
}
