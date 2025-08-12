// /******************************************************************************

//                               بسم الله الرحمان الرحيم
// author:mfaiz_1
// MEMOISATION APPROACH FROG JUMP WITH K DISTANCES
// *******************************************************************************/
// #include "bits/stdc++.h"
// #define int long long
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

// int solveDp(vector<int>&h,int idx,vector<int>&dp,int k){
//     if(idx==0) return 0;
//     if(dp[idx]!=-1) return dp[idx];
//     int mstep=INT_MAX;
//     for(int j=1;j<=k;j++){
//         if(idx-j>=0){
//             int jump=solveDp(h,idx-j,dp,k) + abs(h[idx]-h[idx-j]);
//             mstep=min(mstep,jump);
//         }
//     }
//     return dp[idx]=mstep;
// }
// void funny_3(){
//     int n,k;cin>>n>>k;
//     vi h(n);
//     cin>>h;
//     vector<int>dp(n,-1);
    
//     int ans=solveDp(h,n-1,dp,k);
//     cout<<ans<<endl;
    
    
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

  

/******************************************************************************

                              بسم الله الرحمان الرحيم
author:mfaiz_1
TABULATION APPROACH .
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


void funny_3(){
    int n,k;
    cin>>n>>k;
    vi h(n);
    cin>>h;
    vi dp(n,-1);
    dp[0]=0;

    for(int i=1;i<n;i++){
        int mnstep=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump= dp[i-j] +abs(h[i]-h[i-j]);
                mnstep=min(mnstep,jump);
            }
        }
        dp[i]=mnstep;
    }
    cout<< dp[n-1]<<endl;

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

    