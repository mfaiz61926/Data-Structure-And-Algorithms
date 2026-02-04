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
/* // OTHER SOL 1
	#include <bits/stdc++.h>  
using namespace std;
int dp[312][312];  // dp[i][j] = max attainable number in range {i...j}
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream cin("248.in");
    ofstream cout("248.out");
    int n, a[312]; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) dp[i][i] = a[i]; // base case
    int ans = *max_element(a, a+n);
    for(int l = 2; l <= n; l++){
        for(int i = 0; i <= n-l; i++){
            int j = i+l-1;
            for(int k = i; k < j; k++)
                if(dp[i][k]==dp[k+1][j])
                    dp[i][j] = max(dp[i][j], dp[i][k]+1);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
*/
/*
	signed main() // other sol 2
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    setIO("248");
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp (n, vector<int> (n, -1)); //dp[i][j] = final element the range i..j can be merged into as a single element, -1 if it cannot be merged into a single element
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                dp[i][j] = a[i];
            } else {
                for (int k = i; k < j; ++k) {
                    if (dp[i][k] != -1 and dp[i][k] == dp[k + 1][j]) {
                        dp[i][j] = dp[i][k] + 1;
                    }
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
*/

void solve() {
    int n;
    cin >> n;
    vi v(n);
    int ans  = INT_MIN;
    for(int i = 0; i < n; i++) cin >> v[i], ans = max(ans, v[i]);

    vector<vector<int>>dp(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++) dp[i][i] = v[i];

    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            for(int k = i; k < j; k++){
                if(dp[i][k] != -1 && dp[k+1][j] != -1 && dp[i][k] == dp[k+1][j]){
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("248.in",  "r",  stdin);
    freopen("248.out", "w", stdout);
#endif

    // clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}