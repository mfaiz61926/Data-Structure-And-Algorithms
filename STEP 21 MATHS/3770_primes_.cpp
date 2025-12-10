// class Solution { NO 1 SOLUTION
// public:
//     int largestPrime(int n) {
//         if(n < 2) return 0;
//         //prefix sum pri array
//         vector<int>pri = { 
//             2, 5, 17, 41, 197, 281, 7699, 8893, 22039,
//             24133, 25237, 28697, 32353, 37561, 38921, 43201,
//             44683, 55837, 61027, 66463, 70241, 86453, 
//             102001, 109147, 116533, 119069, 121631, 129419, 
//             132059, 263171, 287137, 325019, 329401, 333821, 
//             338279, 342761, 360979, 379667, 393961, 398771
//         };
//         //do binary search;

//         int low = 0; 
//         int high = pri.size()-1;

//         while(low <= high){
//             int mid = low + (high - low ) /2;
//             if(pri[mid] == n) return pri[mid];
//             else if(pri[mid] > n) high = mid - 1;
//             else low = mid + 1;
//         }
//         return pri[high];


//     }
// };


// class Solution { NO 2 SOLUTION
// public:
//     bool is_prime(int n) {
//         if (n < 2) return false;
//         if (n % 2 == 0) return n == 2;
//         for (int i = 3; i * i <= n; i += 2) {
//             if (n % i == 0) return false;
//         }
//         return true;
//     }

//     int largestPrime(int n) {
//         long long sum = 2;
//         int res = 0;
//         if (n >= 2) res = 2;

//         for (int x = 3; sum + x <= n; x++) {
//             if (is_prime(x)) {
//                 sum += x;
//                 if (sum <= n && is_prime(sum)) {
//                     res = sum;
//                 }
//             }
//         }
//         return res;
//     }
// };



class Solution {
public:
    int largestPrime(int n) { // no 3 , my first intution.
        if(n < 2) return 0;
        vector<int>pri(n+1,1);
        pri[0] = 0;
        pri[1] = 0;
        for(int i = 2; i * i <=n; i++){
            if(pri[i])
            for(int j = i*i; j <=n; j+=i){
                pri[j] = 0;
            }
        }
        int sum = 0;
        int ans = -1;
        for(int i = 2; i <= n; i++){
            if(pri[i]){
                sum += i;
                if(sum > n) break;
                if(pri[sum]) ans = sum;
            }
        }

        return ans;

    }
};