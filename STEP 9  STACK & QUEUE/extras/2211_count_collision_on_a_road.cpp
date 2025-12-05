#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCollisions(string directions) {
        int cnt = 0;
        stack<char> st;

        for (char c : directions) {
            if (c == 'R') {
                st.push(c);
            }
            else if (c == 'L') {
                // Collide with all previous 'R'
                if (!st.empty() && st.top() == 'R') {
                    cnt += 2;     // first R + L
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        cnt++;    // each extra R collides
                        st.pop();
                    }
                    st.push('S');
                }
                else if (!st.empty() && st.top() == 'S') {
                    cnt++;
                    st.push('S');
                }
                else {
                    st.push('L');
                }
            }
            else { // c == 'S'
                while (!st.empty() && st.top() == 'R') {
                    cnt++;  // R hits S
                    st.pop();
                }
                st.push('S');
            }
        }
        return cnt;
    }
};
