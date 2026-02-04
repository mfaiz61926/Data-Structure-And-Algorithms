#include <bits/stdc++.h>
using namespace std;

//APPROACH - 1
class Solution {
public:
//for storing already solved problems
    unordered_map<string,bool> mp;
    
    
    bool isScramble(string s1, string s2) {
        //base cases
        
        int n = s1.size();
        
        //if both string are not equal in size
        if(s2.size()!=n)
            return false;
        
        //if both string are equal
        if(s1==s2)
         return true;   
        
            
        
        //if code is reached to this condition then following this are sure:
        //1. size of both string is equal
        //2.  string are not equal
        //so size is equal (where size==1) and they are not equal then obviously false
        //example 'a' and 'b' size is equal ,string are not equal
        if(n==1)
            return false;
        
        string key = s1+" "+s2;
        
		//check if this problem has already been solved
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        //for every iteration it can two condition 
        //1.we should proceed without swapping
        //2.we should swap before looking next
        for(int i=1;i<n;i++)
        {

            //ex of without swap: gr|eat and rg|eat
            bool withoutswap = (
                //left part of first and second string
                isScramble(s1.substr(0,i),s2.substr(0,i)) 
                
                &&
                
                //right part of first and second string;
                isScramble(s1.substr(i),s2.substr(i))
                );
            
            
            
            //if without swap give us right answer then we do not need 
            //to call the recursion withswap
            if(withoutswap)
                return true;
            
            //ex of withswap: gr|eat  rge|at
			//here we compare "gr" with "at" and "eat" with "rge"
            bool withswap = (
                //left part of first and right part of second 
                isScramble(s1.substr(0,i),s2.substr(n-i)) 
                
                &&
                
                //right part of first and left part of second
                isScramble(s1.substr(i),s2.substr(0,n-i)) 
                );
            
            
            
            //if withswap give us right answer then we return true
            //otherwise the for loop do it work
            if(withswap)
                return true;
            //we are not returning false in else case 
            //because we want to check further cases with the for loop
        }
        
        
        return mp[key] = false;
        
    }
};

/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Fx96uB9EIDQ
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/scramble-string/
*/


//Appoach-1 (Recursion + Memo)
class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(string s1, string s2) {

        if(s1 == s2) //both string empty covered here too
            return true;
        if(s1.length() != s2.length())
            return false;

        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end())
            return mp[key];

        bool result = false;
        int n = s1.length();
        for(int i = 1; i<n; i++) {
            /*
            Example : "great"  "eatgr"
            if swapped at i = 2
            we compare s1.substr(0, i) i.e "gr"  with s2.substr(n-i, i) i.e. "gr"
            && s1.substr(i, n-i) i.e "eat"  with s2.substr(0, n-i) i.e. "eat"
            */

            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i)) &&
                           solve(s1.substr(i, n-i), s2.substr(0, n-i));
            if(swapped) { //if we find they are scrambled, we don't need to check further
                result = true;
                break;
            }
            /*
            Example : "great"  "great"
            if not swapped at i = 2
            we compare s1.substr(0, i) i.e "gr"  with s2.substr(0, i) i.e. "gr"
            && s1.substr(i, n-i) i.e "eat"  with s2.substr(i, n-i) i.e. "eat"
            */

            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
                               solve(s1.substr(i, n-i), s2.substr(i, n-i));
            if(not_swapped) { //if we find they are scrambled, we don't need to check further
                result = true;
                break;
            }

        }

        return mp[key] = result;
    }
    bool isScramble(string &s1, string &s2) {
        mp.clear();
        return solve(s1, s2);
    }
};