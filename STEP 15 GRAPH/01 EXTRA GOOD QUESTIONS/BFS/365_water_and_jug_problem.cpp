#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return (z == 0 || (z - x <= y && z % __gcd(x,y) == 0));
    }
};

// class Solution {
// public:
//     bool canMeasureWater(int x, int y, int z) {
//         if(x + y == z || x == z || y == z || z == 0) return true;
//         if(x + y < z) return false;
//         int d = __gcd(x, y);
//         return z % d == 0;
//     }
// };

int main(){
    Solution s;
    bool ans = s.canMeasureWater(3, 4, 8);
    cout << ans << endl;
}

