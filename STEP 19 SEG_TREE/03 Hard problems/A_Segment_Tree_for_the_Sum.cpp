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

struct SegTree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n; // n = _n also correct
		st.resize(4 * n, 0);
	}

	void build(int start, int end, int node, vector<int> &v) {
		// leaf node base case
		if (start == end) {
			st[node] = v[start];
			return;
		}

		int mid = (start + end) / 2;

		// left subtree is (start,mid)
		build(start, mid, 2 * node + 1, v);

		// right subtree is (mid+1,ending)
		build(mid + 1, end, 2 * node + 2, v);

		st[node] = (st[node * 2 + 1] + st[node * 2 + 2]);
	}

	int query(int start, int end, int l, int r, int node) {
		// non overlapping case  [l r] [start end] OR [start end] [l r]
		if (start > r || end < l) {
			return 0;
		}

		// complete overlap  [l start end r]
		if (l <= start && end <= r) {
			return st[node];
		}

		// partial case
		int mid = (start + end) / 2;

		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, end, l, r, 2 * node + 2);

		return q1 + q2;
	}

	void update(int start, int end, int node, int index, int value) {
		// base case
		if (start == end) {
			st[node] = value;
			return;
		}

		int mid = (start + end) / 2;
		if (index <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, index, value);
		}
		else {
			// right
			update(mid + 1, end, 2 * node + 2, index, value);
		}

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int idx, int val) {
		update(0, n - 1, 0, idx, val);
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi v(n);
    cin >> v;

    SegTree tree;
    tree.init(n);
    tree.build(v);
    
    for(int i = 0; i < m; i++){
        int t; cin >> t;
        if(t == 1){
            int idx, val;
            cin >> idx >> val;
            tree.update(idx, val);

        }
        else{
            int l, r;
            cin >> l >> r;
            cout << tree.query(l, r - 1) << endl;
        }
    }
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