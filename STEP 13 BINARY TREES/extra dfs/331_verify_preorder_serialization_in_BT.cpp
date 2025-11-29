// In Preorder traversal we first record the current node value and then we traverse the left and right children of that node.

// After observing the preorder traversal of various binary trees we notice two things :

// A leaf node will always be followed by two '#' ( which represent NULL values and also that we do not have to traverse this subtree).
// We can replace an entire subtree with a '#' after we have finished traversing that subtree. The '#' indicates that this subtree has already been traversed and we need to move on to the next child.
// Refer the example below to understand the concept better.

// image   make one element and two # -> only one # in stack

// A stack data structure will be of great help to track the nodes and remove them easily.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream s(preorder);
        stack<string>st;
        string str;

        while(getline(s, str, ',')){
            if(st.empty() || str != "#") st.push(str);
            else{
                while(!st.empty() && st.top() == "#"){
                    st.pop();
                    if(st.empty()) return false;
                    else st.pop();
                }

                st.push(str);
            }
        }
        return st.size() == 1 && st.top() == "#";

    }
};