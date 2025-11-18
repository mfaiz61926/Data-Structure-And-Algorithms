/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=CAVnGkDzqAs
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
*/
#include <bits/stdc++.h>
using namespace std;
//Sliding window - Separate function to check vowel
class Solution {
public:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int maxVowels(string s, int k) {
        int n = s.length();
        
        int maxV  = 0;
        int count = 0;
        int i = 0, j = 0;
        
        while(j < n) {
            
            if(isVowel(s[j]))
                count++;
            
            if(j-i+1 == k) {
                maxV = max(maxV, count);
                if(isVowel(s[i]))
                    count--;
                i++;
            }
            
            j++;
        }
        
        return maxV;
    }
};


//Sliding Window - Writing a lambda function to check vowel
class Solution {
public:
    
    int maxVowels(string s, int k) {
        
        auto isVowel = [&](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        
        int n = s.length();
        
        int maxV  = 0;
        int count = 0;
        int i = 0, j = 0;
        
        while(j < n) {
            
            if(isVowel(s[j]))
                count++;
            
            if(j-i+1 == k) {
                maxV = max(maxV, count);
                if(isVowel(s[i]))
                    count--;
                i++;
            }
            
            j++;
        }
        
        return maxV;
    }
};


//MY APPROACH
class Solution {
public:
    bool check(char &i){
        if(i == 'a' || i == 'e' || i == 'i'|| i =='o'|| i == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        int mx = 0;
        int cnt = 0;
        for(int r = 0; r < n; r++){
            if(check(s[r])){
                cnt++;
            }
            if(r - i + 1 == k){
                mx = max(mx, cnt);
                if(check(s[i]))cnt--;
                i++;
            }
        }
        return mx;
    }
};