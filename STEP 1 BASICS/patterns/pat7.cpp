#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print Pattern 7
    void pattern7(int N) {
        // Outer loop for rows
        for (int i = 0; i < N; i++) {
            
            // Print leading spaces (N - i - 1 spaces)
            for (int j = 0; j < N - i - 1; j++) {
                cout << " ";
            }

            // Print stars (2*i + 1 stars)
            for (int j = 0; j < 2 * i + 1; j++) {
                cout << "*";
            }

            // Print trailing spaces (optional, same count as leading spaces)
            for (int j = 0; j < N - i - 1; j++) {
                cout << " ";
            }

            // Move to next row
            cout << endl;
        }
    }
};

int main() {
    Solution sol;
    int N = 5;
    sol.pattern7(N);
    return 0;
}
