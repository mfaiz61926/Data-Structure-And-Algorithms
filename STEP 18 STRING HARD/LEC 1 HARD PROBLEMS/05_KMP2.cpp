#include <bits/stdc++.h>
using namespace std;
//FOR CHECKING PATTERN PRESENT OR NOT IN TXT.
void computeLps(string& pat, vector<int>& lps) {
        int m = pat.size();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
        int strStr(string haystack, string needle) {
            int n=haystack.size();
            int m=needle.size();
            vector<int>lps(m,0);
            computeLps(needle,lps);

            int i=0;
            int j=0;
            int ans=-1;
            while(i<n){
                if(needle[j]==haystack[i]){
                    i++;
                    j++;
                }
                if(j==m){
                    // ans.push_back(i-j);
                    // j=lps[j-1];
                    ans=i-j;
                    break;
                }
                else if(i<n && needle[j]!=haystack[i]){
                    if(j!=0){
                        j=lps[j-1];
                    }else{
                        i++;
                    }
                }
            }
            return ans;
        }