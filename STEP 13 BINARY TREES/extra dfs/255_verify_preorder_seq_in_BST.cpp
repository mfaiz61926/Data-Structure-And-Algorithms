#include <bits/stdc++.h> 
using namespace std;
bool isBSTPreorder(vector<int> &arr) 
{
    // Write your code here.
    int n = arr.size();
    int root = -1e9;
    stack<int>st;
    for(int i = 0; i < n; i++){
        if(arr[i] < root) return false;
        while(!st.empty() && arr[i] > st.top()){
            root = st.top();
            st.pop();
        }
        st.push(arr[i]);
    }
    return true;
}