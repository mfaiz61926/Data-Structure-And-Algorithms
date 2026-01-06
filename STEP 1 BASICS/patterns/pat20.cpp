#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print Pattern 20
    void pattern20(int n) {
        // Initialize spaces between star blocks
        int spaces = 2 * n - 2;

        // Loop for rows
        for (int i = 1; i <= 2 * n - 1; i++) {
            // Calculate stars for first half
            int stars = i;

            // Adjust stars for second half
            if (i > n) stars = 2 * n - i;

            // Print left stars
            for (int j = 1; j <= stars; j++) {
                cout << "*";
            }

            // Print spaces
            for (int j = 1; j <= spaces; j++) {
                cout << " ";
            }

            // Print right stars
            for (int j = 1; j <= stars; j++) {
                cout << "*";
            }

            // Move to next line
            cout << endl;

            // Adjust spaces for next row
            if (i < n) spaces -= 2;
            else spaces += 2;
        }
    }
};

int main() {
    // Create solution object
    Solution sol;
    // Define N
    int N = 5;
    // Call pattern function
    sol.pattern20(N);
    return 0;
}
