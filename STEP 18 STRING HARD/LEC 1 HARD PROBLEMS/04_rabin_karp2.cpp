#include <bits/stdc++.h>
using namespace std;
//for check if patter present or not;
bool RabinKarp(string &pat, string &txt) {
        // code here. its my code   .....
        int n = txt.size();
        int m = pat.size();
        
        //constants;
        int d=256;
        int q=101;
        int p=0;
        int t=0;
        int h=1;
        
       bool ans=false;
        
        //precompute h=pow(d,m-1)%q;
        for(int i=0;i<m-1;i++){
            h=(h*d)%q;
        }
        
        //initial hash values
        for(int i = 0; i < m; i++){
             p = (d * p + pat[i]) % q;
             t = (d * t + txt[i]) % q;
        }
        
        for(int i=0;i<=n-m;i++){
            if(p==t){
                bool match=true;
                for(int j=0 ;j< m ;j++ ){
                    if(txt[i+j]!=pat[j]){
                        match=false;
                        break;
                    }
                }
                if(match){
                    ans =true;
                    break;
                }
            }
            
            if(i<n-m){
                t=(d*(t-txt[i]*h)+txt[i+m])%q;
                
                if(t<0){
                    t+=q;
                }
            }
        }
        return ans;
    }