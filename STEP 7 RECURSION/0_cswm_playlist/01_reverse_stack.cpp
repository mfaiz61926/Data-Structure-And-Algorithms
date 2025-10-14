// link -> https://www.geeksforgeeks.org/problems/reverse-a-stack/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        
        int top = st.top();
        st.pop();
        
        reverseStack(st);
        
        stack<int>temp;
        
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        
        st.push(top);
        
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
 
    }
};