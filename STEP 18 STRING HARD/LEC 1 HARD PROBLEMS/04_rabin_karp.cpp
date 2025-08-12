// BRUTE FORCE
// #include <bits/stdc++.h>

// using namespace std;

// class Solution {
//   public:
//     void searchPattern(string & text, string & pattern) {

//       int n = text.length();
//       int m = pattern.length();

//       int j;
//       for (int i = 0; i <= n - m; i++) {

//         for (j = 0; j < m; ++j) {
//           if (pattern[j] != text[i + j]) {
//             break;
//           }
//         }

//         if (j == m) {
//           cout << "index = " << i << "\n";
//         }
//       }
//     }
// };
// int main() {

//   string text = "AABAACAADAABAABA";
//   string pattern = "AABA";

//   Solution obj;
//   obj.searchPattern(text, pattern);
//   return 0;
// }
// Output:

// index = 0
// index = 9
// index = 12

// Time complexity: O(m*(n-m+1)) [Worst case time complexity] where m = length of pattern, n = length of text.

// Space complexity: O(1)



//RABIN KARP ALGO
#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp Algorithm to find all occurrences of a pattern in a given text
void rabinKarpAlgo(string &pattern, string &text, int q) {
    int m = pattern.size();  // Length of the pattern
    int n = text.size();     // Length of the text
    int i, j;
    int hash_p = 0;          // Hash value for the pattern
    int hash_t = 0;          // Hash value for current window of text
    int h = 1;
    int d = m + n;           // Base value for hash calculation (normally 256, but m+n used here)

    // The value of h would be "pow(d, m-1) % q"
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the initial hash values for the pattern and the first window of the text
    for (i = 0; i < m; i++) {
        hash_p = (pattern[i] + d * hash_p) % q;
        hash_t = (text[i] + d * hash_t) % q;
    }

    // Slide the pattern over text one character at a time
    for (i = 0; i <= n - m; i++) {

        // If the hash values match, check for characters one by one
        if (hash_p == hash_t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            // If the pattern is found
            if (j == m)
                cout << "Pattern is found at index : " << i << "\n";
        }

        // Calculate hash value for the next window of text:
        // Remove the leading digit and add the trailing digit
        if (i < n - m) {
            hash_t = (d * (hash_t - text[i] * h) + text[i + m]) % q;

            // Convert negative hash_t to positive
            if (hash_t < 0)
                hash_t = (hash_t + q);
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";   // The text to search in
    string pattern = "GEEK";           // The pattern to search for
    int q = 101;                       // A prime number for hashing

    rabinKarpAlgo(pattern, text, q);   // Call the search function
}
