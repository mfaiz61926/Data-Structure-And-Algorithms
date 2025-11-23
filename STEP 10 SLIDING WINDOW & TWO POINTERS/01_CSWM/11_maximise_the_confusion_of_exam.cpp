#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int maxConsecutiveAnswers(string s, int k) {
//         int n = s.size();
//         int result = 0;
//         int l = 0;
//         int cntF = 0;
//         for(int r = 0; r < n; r++){ // fliping F -> T
//             if(s[r] == 'F'){
//                 cntF++;
//             }
//             while(cntF > k){
//                 if(s[l] == 'F')cntF--;
//                 l++;
//             }
//             result = max(result, r - l + 1);
//         }

//         //now flip T->F
//         l = 0;
//         int cntT = 0;
//         for(int r = 0; r < n; r++){
//             if(s[r] == 'T') cntT++;
//             while( cntT > k){
//                 if(s[l] == 'T')cntT--;
//                 l++;
//             }
//             result = max(result, r - l + 1);
//         }

//         return result;
//     }
// };

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int result = 0;
        int l = 0;
        map<char,int>mp;
        for(int r = 0; r < n; r++){
            mp[s[r]]++;
            while(min(mp['T'], mp['F']) > k){
                mp[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};