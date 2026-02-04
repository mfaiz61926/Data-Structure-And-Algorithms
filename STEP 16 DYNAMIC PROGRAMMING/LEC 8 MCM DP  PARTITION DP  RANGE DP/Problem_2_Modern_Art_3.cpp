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


// Define $\texttt{dp}[i][j]$ as the minimum number of paintings to paint the range
// $[i, j]$. Then, one of two things can happen when combining ranges
// $[i, j], [j + 1, k]$:
// $A[i] == A[k]$. This means that the range $[i, k]$ has a common color for each
// endpoint. Therefore, we can "save" a color when merging the two ranges.
// $$\texttt{dp}[i][k] = \min(\texttt{dp}[i][k], \texttt{dp}[i][j] + \texttt{dp}[j + 1][k] - 1)$$

// $A[i] \neq A[k]$. This means that there is no common color for the endpoint.
// Since we cannot "save" a color when merging the two intervals, simply add
// them together.

/* SOLUTION 1 USACO
int n;
int a[305], dp[305][305];

signed main()
{
    fast;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    //base case
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dp[i][j] = 1;
            else dp[i][j] = LONG_LONG_MAX;
        }
    }
    //transition
    for(int d = 2; d <= n; d++){
        for(int i = 1; i <= n - d + 1; i++){
            int j = i + d - 1;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] - (a[i] == a[j]));
            }
            // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    cout << dp[1][n] << endl;
}*/


/* SOLUTION 2
int n, arr[301];
vector<vector<int>> dp(301, vector<int> (301, 556868));

int main(){
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i], dp[i][i] = 1;
	
	
	for(int l = n; l >= 1; l--){
		for(int r = l; r <= n; r++){
			for(int k = l; k < r; k++){
				if(arr[l] == arr[r]) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] - 1);
				else dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
		}
	}
	
	cout << dp[1][n] << endl;
	
	return 0;
}

*/
void solve() {
    int n;
    cin >> n;
    vi v(n);
    cin >> v;

    vector<vector<int>>dp(n, vector<int>(n, 1e9));

    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] - (v[i] == v[j]));
            }
        }
    }

    cout << dp[0][n-1];
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