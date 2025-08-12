// /******************************************************************************

//                               بسم الله الرحمان الرحيم
// author:mfaiz_1

// *******************************************************************************/
// #include "bits/stdc++.h"
// #define int long long
// #define ll  long long 
// #define uint unsigned long long
// #define vi vector<int>
// #define vvi vector<vi >  
// #define vb vector<bool>
// #define vvb vector<vb >
// #define fr_3(i,n) for(int i=0; i<(n); i++)
// #define fb_3(i,a,n) for(int i=(a); i<=(n); i++)
// #define nl cout<<"\n"
// #define dbg(var) cout<<#var<<"="<<var<<" "
// #define all_3(v) v.begin(),v.end()
// #define srt_3(v)  sort(v.begin(),v.end())         // sort 
// #define mxe_3(v)  *max_element(v.begin(),v.end())     // find max element in vector
// #define mne_3(v)  *min_element(v.begin(),v.end())     // find min element in vector
// #define unq_3(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// // make sure to sort before applying unique // else only consecutive duplicates would be removed 
// #define bin(x,y)  bitset<y>(x) 
// using namespace std;
//      // Hardcoded, directly change from here for functions!



// int MOD=1e9+7; 
// void mod_add(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
// void mo_dsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
// void mo_dmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// // ================================== take ip/op like vector,pairs directly!==================================
// template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
// template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
// template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
// template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
// template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// // ===================================END Of the input module ==========================================
// vector<int> z_function(string s) {
//     vector<int> p(s.size());
//         for (int i = 1, j = 0; i < s.size(); i++) {
//                 while (j > 0 and s[j] != s[i]) j = p[j-1];
//                 if (s[j] == s[i]) j++;
//                 p[i] = j;
//         }
//         return p;
// }

// void funny_3(){
//    string s; cin >> s;
//         int n = s.size();
//         vector<int> p = z_function(s);
//         int j = p.back();
//         if (j > 0) {
//                 for (int i = 0; i < n-1; i++) if (p[i] == j) {
//                         cout << s.substr(0, j) << endl;
//                         return ;
//                 }
//                 j = p[j-1];
//                 if (j > 0) {
//                         cout << s.substr(0, j) << endl;
//                         return ;
//                 }
//         }
//         cout << "Just a legend" << endl;
// }

// int32_t main()
// {
 
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);

//     int t_c_3= 1;
//     // cin >> t_c_3;
//     while (t_c_3--)
//     {
//         funny_3();
//     }
//     return 0;
// }




//SECOND APPROACH
/******************************************************************************

                              بسم الله الرحمان الرحيم
author:mfaiz_1

*******************************************************************************/
#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >  
#define vb vector<bool>
#define vvb vector<vb >
#define fr_3(i,n) for(int i=0; i<(n); i++)
#define fb_3(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all_3(v) v.begin(),v.end()
#define srt_3(v)  sort(v.begin(),v.end())         // sort 
#define mxe_3(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne_3(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq_3(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
     // Hardcoded, directly change from here for functions!



int MOD=1e9+7; 
void mod_add(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void mo_dsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void mo_dmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void funny_3() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = z_function(s);

    vector<int> candidates;

    // Find all prefix-suffix lengths
    for (int i = 1; i < n; i++) {
        if (z[i] == n - i) {
            candidates.push_back(n - i);  // suffix of len (n - i) == prefix
        }
    }

    // Check if any of those prefix-suffix lengths appear somewhere in middle
    for (int len : candidates) {
        for (int i = 1; i < n - len; i++) {
            if (z[i] >= len) {
                cout << s.substr(0, len) << "\n";
                return;
            }
        }
    }

    cout << "Just a legend\n";
}


int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int t_c_3= 1;
    // cin >> t_c_3;
    while (t_c_3--)
    {
        funny_3();
    }
    return 0;
}

    
    