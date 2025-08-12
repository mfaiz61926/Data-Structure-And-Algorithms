#include <bits/stdc++.h>
using namespace std;
int binaryTodeci(string s){
    int n=s.length();
    int p2=1,num=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1') num=num+p2;
        p2=p2*2;
    }
    return num;
}

int main() {
    string s="111";
    cout<<binaryTodeci(s)<<endl;
    return 0;
}