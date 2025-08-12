 #include <bits/stdc++.h>
 using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);//initializing with 0.
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// int strStr(string haystack, string needle) {  THIS IS LEETCODE QUESTION SOLUTION.
//         vector<int> temp=z_function(needle+'$'+haystack);
//         int n=needle.size();
//         int count=-1;
//         //Cheking after the dollar sign
//         for(int i=n+1;i<temp.size();i++){
//             if(temp[i]==n){
//                 count=i-n-1;
//                 break;
//             }
//         }
//         return count;
// }

int main() {  // THIS DHAGA KHOL UNDERSTANDING OF WORKING .
    string text = "sadbutsadassdasa";
    string pat = "sad";
    string s=pat+ "$" + text;
    vector<int>temp=z_function(s);
    int n=text.size();
    int m=pat.size();
    int nm=s.size();
    // for(int i=0;i<temp.size();i++){  //FOR PRINTING Z ARRAY.
    //     cout<<temp[i]<<" ";
    // }cout<<endl;

    // int ans=-1;
    vector<int>ans;
    for(int i =m+1; i<nm; i++){
        if(temp[i]==m){
           int  curr=i-m-1;
           ans.push_back(curr);

          
        }
    }
    for(auto &it:ans){
        cout<<it<<" ";
    }cout<<'\n';
}






// class Solution {  // FOR EXPLANAITON....... READ AND REVISE.
// public:
// /*
//     Definition of the z function:
//         - Starting from index i till end howmany characters(in sequence) matches with the start is the zscore for that index.
//         - Basically from start howmuch longer string is matching with substring starting with the particular index i.

//         Time Complexity: is depended on the string input but mostly it will be O(n) as in the worst case in which we need to traverse full string each time(when all the characters are equal) we are just copying the values using the windows.

//         Basic idea behind the working of this algorithm:
//             - while(i+z[i]<n && s[i+z[i]]==s[z[i]])z[i]++; (This line noting but the brute force)
//                 - here the index is not being updated because z[i] is working as the index here.
//                 - each time z[i] will increase by 1 and subsequenet characters will keep being compared.
//             - we are optimizing this brute force solution using the window.
//             - Window is set from previous index to the index till the substring is matchin with start.
//             - now the logic is built based on this idea if a index is inside the window the it is similar to substring starting at the front and we can directly copy answer from there else we will use the brute force and find the answer and update window according to that.
// */
//     vector<int> z_function(string s) {
//     int n = s.size();
//     vector<int> z(n);//initializing with 0.
//     int l = 0, r = 0;
//     for(int i = 1; i < n; i++) {
//         if(i < r) {
//             z[i] = min(r - i, z[i - l]);
//         }
//         while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
//             z[i]++;
//         }
//         if(i + z[i] > r) {
//             l = i;
//             r = i + z[i];
//         }
//     }
//     return z;
// }
//     int strStr(string haystack, string needle) {
//         vector<int> temp=z_function(needle+'$'+haystack);
//         int n=needle.size();
//         int count=-1;
//         //Cheking after the dollar sign
//         for(int i=n+1;i<temp.size();i++){
//             if(temp[i]==n){
//                 count=i-n-1;
//                 break;
//             }
//         }
//         return count;
//     }
// };