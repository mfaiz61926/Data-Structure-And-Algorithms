/******************************************************************************

                              بسم الله الرحمان الرحيم
author:mconq(Mohd_Faiz)

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define fr_3(i,n)      for(int i=0; i<(n); i++)
#define fb_3(i,a,n)    for(int i=(a); i<=(n); i++)
#define srt_3(v)       sort(v.begin(),v.end())         // sort 
#define mxe_3(v)       *max_element(v.begin(),v.end())     // find max element in vector
#define mne_3(v)       *min_element(v.begin(),v.end())     // find min element in vector
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl


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


inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

void solve1() {
    int n;
    cin >> n;
    vi v(n);
    cin >> v;

    vector<vector<int>>dp(n + 1, vector<int>(n + 1));
//first look at substrings, now we want the answer for this substring, take an array 
//1 4 4 2 3 2 1 we can start by looking for the starting and ending point of a palindromic sequence. We know starting and ending must be same so for each subarray we iterate from the 2nd element till last in hopes of finding a matching element with the start of the subarray, ie a[I] and take care of the in-betweens later.
//We need to make sure that everything in between is a palindrome, for which we can again start looking for an ending and start with same value, and then keep doing it recursively. Also we must write a case where we don't match a[i] with any character, which will amount to deleting it as a single character (default palindrome) and adding the answer for the remaining substring. 
//There is one more nuance we need to take care of. Even palindromes. 
//Let's clearly keep in mind what we are doing exactly, we are peeling of layers of potential palindromic sequence and digging deeper. Doing this we are not increasing our answer at any step but rather we hope to find that single centre element at one point, which will amount to increment in one count for the whole palindromic "subsequence" (subsequence because we will remove the in-betweens first before the remaining numbers form a palindromic subarray). But for even palindromes, we can't hope to find a central piece, only two adjacent same elements, which kind of forms the "core" of the palindromic subsequence, eg 1 1 2 3 3 4 2 1, here we remove 1 first then 4 then remaining is 1 2 3 3 2 1, which turns to 2 3 3 2 then 3 3, which forms the "core", hence we don't peel further down to get "" (empty string) but stop at an even core and add +1 to our current recursion/dp. also note that even cored palindromic subsequences will only we required when the core is actually one after the other, otherwise we can include another element between them.


    for(int len = 1; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;

            dp[i][j] = 1 + dp[i + 1][j];
            if(i + 1 < n &&  v[i] == v[i + 1]) dp[i][j] = 1 + dp[i + 2][j];
            for(int k = i + 2; k <= j; k++){
                if(v[i] == v[k]){
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k + 1][j]);
                }
            }
        }
    }

    cout << dp[0][n-1] << endl;
}
// void solve() {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++) cin >> v[i];

//     const int INF = 1e9;

//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     vector<vector<bool>> pal(n, vector<bool>(n, true));

//     // build palindrome table
//     for (int i = n - 1; i >= 0; i--) {
//         for (int j = i; j < n; j++) {
//             if (i == j) pal[i][j] = true;
//             else if (v[i] == v[j]) {
//                 if (j - i == 1) pal[i][j] = true;
//                 else pal[i][j] = pal[i + 1][j - 1];
//             } else {
//                 pal[i][j] = false;
//             }
//         }
//     }

//     // dp computation
//     for (int i = n - 1; i >= 0; i--) {
//         for (int j = i; j < n; j++) {
//             dp[i][j] = INF;

//             for (int x = i; x <= j; x++) {

//                 // remove palindrome prefix [i..x]
//                 if (pal[i][x]) {
//                     dp[i][j] = min(dp[i][j],
//                                    (x + 1 < n ? dp[x + 1][j] : 0) + 1);
//                 }

//                 // special merge case
//                 if (v[i] == v[x] && x > i + 1) {
//                     dp[i][j] = min(dp[i][j],
//                                    dp[i + 1][x - 1] +
//                                    (x + 1 < n ? dp[x + 1][j] : 0));
//                 }
//             }
//         }
//     }

//     cout << dp[0][n - 1] << endl;
// }
typedef long long ll;
void solve(){
    
    int n; cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(n,1e11));
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        dp[i][i] = 1;
    }
    for (int r = 0; r < n; r++){
        for (int l = r-1; l >= 0; l--){
            if (a[l] == a[r]){
                if (l+1 <= r-1) {
                    dp[l][r] = dp[l + 1][r - 1];
                }else{
                    dp[l][r] = 1;
                }
            }
            for (int k = l; k < r; k++){
                if (a[l] == a[k]) {
                    ll cur = 0;
                    if (l+1 <= k-1){
                        cur = dp[l+1][k-1];
                    }else{
                        cur = 1;
                    }
                    if (k+1 <= r){
                        cur += dp[k+1][r];
                    }
                    dp[l][r] = min(dp[l][r], cur);
                }else{
                    dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
    
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt",  "r",  stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    // clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}