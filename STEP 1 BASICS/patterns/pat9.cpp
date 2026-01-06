#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print the erect (upright) pyramid
    void erect_pyramid(int N) {
        for (int i = 0; i < N; i++) {
            // Print spaces before stars
            for (int j = 0; j < N - i - 1; j++) {
                cout << " ";
            }
            // Print stars
            for (int j = 0; j < 2 * i + 1; j++) {
                cout << "*";
            }
            // Print spaces after stars
            for (int j = 0; j < N - i - 1; j++) {
                cout << " ";
            }
            cout << endl;
        }
    }

    // Function to print the inverted pyramid
    void inverted_pyramid(int N) {
        for (int i = 0; i < N; i++) {
            // Print spaces before stars
            for (int j = 0; j < i; j++) {
                cout << " ";
            }
            // Print stars
            for (int j = 0; j < 2 * N - (2 * i + 1); j++) {
                cout << "*";
            }
            // Print spaces after stars
            for (int j = 0; j < i; j++) {
                cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int N = 5;
    Solution obj;
    obj.erect_pyramid(N);
    obj.inverted_pyramid(N);
    return 0;
}
