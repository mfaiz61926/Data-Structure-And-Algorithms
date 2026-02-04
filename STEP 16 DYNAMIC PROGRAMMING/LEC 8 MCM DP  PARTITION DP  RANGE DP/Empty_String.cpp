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

const int N = 502;
/*
Editorial

Let $\texttt{dp}[i][j]$ represent the number of ways to empty the substring $[i, j]$.

To calculate $\texttt{dp}[i][j]$, we loop through indices $k$ between $i$ and $j$ where $s[i] = s[k]$.

Then, if we choose to remove $s[i]$ and $s[k]$, we must remove the range $[i + 1, k - 1]$ first (for $s[i]$ and $s[k]$ to be adjacent). Here, the number of ways to remove the range $[i + 1, k - 1]$ is $\texttt{dp}[i + 1][k - 1]$.

We also need to remove $[k + 1, j]$ for the whole substring $[i, j]$ to be removed (the number of ways to do this is $dp[k + 1][j]$).

Since we can remove the substring $[i, k]$ and $[k + 1, j]$ in any order, we also multiply this by ${(j - i + 1) / 2}\choose {(k - i + 1) / 2}$ (notice that we divide the sizes by two because we remove the letters in pairs).

Thus our transition would be

$$\texttt{dp}[i][j] = \sum{\texttt{dp}[i + 1][k - 1] * \texttt{dp}[k + 1][j] * {{(j - i + 1) / 2}\choose {(k - i + 1) / 2}}}$$

such that $s[i] = s[k]$.
*/
void solve() {

    vector<vector<int>>ncr(N, vector<int>(N, 0));
    ncr[0][0] = 1;
    for (int i = 0; i < N; i++) ncr[i][0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
            ncr[i][j] %= MOD;
        }
    }

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>>dp(n+2, vector<int>(n+2, 0));

    for (int i = 0; i <= n + 1; i++){
        for (int j = i + 1; j <= n + 1; j++){
            dp[j][i] = 1;
        }     
    }
    

    for(int len = 2; len <=n ;len+=2){ // optimisation len+=2  bcoz taking 2 adjacent ele
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len -1 ;
            for(int k = i+1; k <= j; k+=2){ // optimisation  k+=2
                if (s[i] == s[k]) {
                    dp[i][j] += ((dp[i + 1][k - 1] * dp[k + 1][j]) % MOD * ncr[(j - i + 1) / 2][(k - i + 1) / 2] % MOD) % MOD;
                    dp[i][j] %= MOD;
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