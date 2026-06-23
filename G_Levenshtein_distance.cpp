// /******************************************************************************

//                               بسم الله الرحمان الرحيم
// Author:mconq(Mohd_Faiz)

// *******************************************************************************/

// #include <bits/stdc++.h>

// using namespace std;

// #define int            long long int
// #define F              first
// #define S              second
// #define pb             push_back
// #define si             set <int>
// #define vi             vector <int>
// #define pii            pair <int, int>
// #define vpi            vector <pii>
// #define vpp            vector <pair<int, pii>>
// #define mii            map <int, int>
// #define mpi            map <pii, int>
// #define spi            set <pii>
// #define endl           "\n"
// #define sz(x)          ((int) x.size())
// #define all(p)         p.begin(), p.end()

// #define fr0(i,n)       for(int i=0; i<(n); i++)
// #define fr1(i,n)       for(int i = 1; i <= n; i++)
// #define fra(i,a,n)     for(int i=(a); i<=(n); i++)

// #define srT(v)         sort(v.begin(),v.end())         // sort 
// #define mxE(v)         *max_element(v.begin(),v.end())     // find max element in vector
// #define mne_3(v)       *min_element(v.begin(),v.end())     // find min element in vector
// #define double         long double
// #define pq_mx          priority_queue <int>
// #define pq_mn          priority_queue <int, vi, greater<int>>
// #define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
// #define print(a)       for(auto x : a) cout << x << " "; cout << endl
// #define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
// #define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

// // my love;
// #define permu(p, a)    iota(all(p), a)


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


// inline int power(int a, int b)
// {
//     int x = 1;
//     while (b)
//     {
//         if (b & 1) x *= a;
//         a *= a;
//         b >>= 1;
//     }
//     return x;
// }

// template <typename Arg1>
// void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
// template <typename Arg1, typename... Args>
// void __f (const char* names, Arg1&& arg1, Args&&... args)
// {
//     const char* comma = strchr (names + 1, ',');
//     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
// }

// //lin one start here
// // ==================== custom to_string helpers ====================

// string to_string(char c) {
//     return string(1, c);
// }

// string to_string(bool b) {
//     return b ? "true" : "false";
// }

// string to_string(const char* s) {
//     return string(s);
// }

// string to_string(const string& s) {
//     return s;
// }

// string to_string(const vector<bool>& v) {
//     string res;
//     for (bool x : v)
//         res += char('0' + x);
//     return res;
// }

// // ================================================================

// struct fenwick {
//     int n;
//     vector<int> fn;

//     void init(int n) {
//         this->n = n;
//         fn.assign(n + 1, 0);
//     }

//     void add(int x, int val) {
//         x++;
//         while (x <= n) {
//             fn[x] += val;
//             x += (x & -x);
//         }
//     }

//     int sum(int x) {
//         x++;
//         int res = 0;
//         while (x > 0) {
//             res += fn[x];
//             x -= (x & -x);
//         }
//         return res;
//     }

//     int sum(int l, int r) {
//         if (l > r) return 0;
//         return sum(r) - sum(l - 1);
//     }
// };

// const int d4r[4]={-1, 0, 1, 0}, d4c[4]={0, 1, 0, -1};
// const int d8r[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8c[8]={0, 1, 1, 1, 0, -1, -1, -1};
// const int N = 200005;
// int dp[101][101];
// int n, m;
// int f(int i, int j, string& a, string& b){
//     if(i >= n){
//         int c = 0;
//         for(int k = j; k < m; k++) c += (b[k] - 'a' + 1);
//         return c;
//     }
//     if(j >= m){
//         int c = 0; 
//         for(int k = i; k < n; k++) c += (a[k] - 'a' + 1);
//         return c;
//     }

//     if(dp[i][j]!= -1) return dp[i][j];
//     int ca = a[i] - 'a' + 1;
//     int cb = b[j] - 'a' + 1;

//     if(a[i] == b[j]) return dp[i][j] = f(i + 1, j + 1, a, b);
//     else return dp[i][j] = min({abs(ca - cb) + f(i + 1, j + 1, a, b), ca + f(i + 1, j, a, b), cb + f(i, j + 1, a, b)});
// }
// void m_conq() {
//         string a, b;
//         cin >> a >> b;
//         n = a.size();
//         m = b.size();
//         memset(dp, -1, sizeof(dp));
//         cout << f(0, 0, a, b) << endl;

// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// // #ifndef ONLINE_JUDGE
// //     freopen("input.txt",  "r",  stdin);
// //     freopen("output.txt", "w", stdout);
// // #endif

//     // clock_t z = clock();

//     int t = 1;
//     // cin >> t;
//     fr1(i, t){
//         // cout << "Case #" <<  i+1 << ": ";
//         m_conq();
//     }

//     // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

//     return 0;
// }


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e6;

int ind(char c){
    return c - 'a' + 1;
}

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0 && j == 0) dp[i][j] = 0;
            else if (i == 0) dp[i][j] = dp[i][j-1] + ind(b[j-1]);
            else if (j == 0) dp[i][j] = dp[i-1][j] + ind(a[i-1]);
            else {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min({
                    dp[i-1][j-1] + abs(ind(a[i-1]) - ind(b[j-1])),
                    dp[i][j-1] + ind(b[j-1]),
                    dp[i-1][j] + ind(a[i-1]) 
                });
            }
        }
    }
    cout << dp[n][m];
    return 0;
}