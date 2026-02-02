// /******************************************************************************

//                               بسم الله الرحمان الرحيم
// author:mconq(Mohd_Faiz)

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
// #define fr_3(i,n)      for(int i=0; i<(n); i++)
// #define fb_3(i,a,n)    for(int i=(a); i<=(n); i++)
// #define srt_3(v)       sort(v.begin(),v.end())
// #define mxe_3(v)       *max_element(v.begin(),v.end())
// #define mne_3(v)       *min_element(v.begin(),v.end())
// #define double         long double
// #define que_max        priority_queue <int>
// #define que_min        priority_queue <int, vi, greater<int>>
// #define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
// #define print(a)       for(auto x : a) cout << x << " "; cout << endl
// #define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
// #define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

// int MOD=1e9+7;

// const int MAXBIT = 20;

// struct Pair {
//     int sum = 0;
//     int count1[MAXBIT];

//     Pair() {
//         memset(count1, 0, sizeof(count1));
//     }

//     Pair(int s) {
//         sum = s;
//         memset(count1, 0, sizeof(count1));
//         for (int i = 0; i < MAXBIT; i++) {
//             int mask = 1LL << i;
//             if (s & mask) count1[i] = 1;
//         }
//     }

//     Pair(const Pair &l, const Pair &r) {
//         sum = l.sum + r.sum;
//         for (int i = 0; i < MAXBIT; i++) {
//             count1[i] = l.count1[i] + r.count1[i];
//         }
//     }
// };

// struct SegTreeLzy {
//     int n;
//     vector<Pair> tree;
//     vector<int> lazy;
//     vector<int> ar;

//     void init(int _n) {
//         n = _n;
//         tree.assign(4*n, Pair());
//         lazy.assign(4*n, 0);
//         ar.assign(n, 0);
//     }

//     void build(int node, int start, int end) {
//         if (start == end) {
//             tree[node] = Pair(ar[start]);
//         } else {
//             int mid = (start + end) / 2;
//             build(node*2, start, mid);
//             build(node*2+1, mid+1, end);
//             tree[node] = Pair(tree[node*2], tree[node*2+1]);
//         }
//     }

//     void propagate(int node, int start, int end) {
//         if (lazy[node] == 0) return;

//         if (start == end) {
//             int val = tree[node].sum ^ lazy[node];
//             tree[node] = Pair(val);
//             lazy[node] = 0;
//         } else {
//             int x = lazy[node];
//             lazy[node] = 0;

//             lazy[node*2] ^= x;
//             lazy[node*2+1] ^= x;

//             int sum = tree[node].sum;

//             for (int i = 0; i < MAXBIT; i++) {
//                 int mask = 1LL << i;
//                 if (x & mask) {
//                     int one = tree[node].count1[i];
//                     int zero = (end - start + 1) - one;
//                     sum += (zero - one) * mask;
//                     tree[node].count1[i] = zero;
//                 }
//             }
//             tree[node].sum = sum;
//         }
//     }

//     int query(int node, int start, int end, int l, int r) {
//         propagate(node, start, end);
//         if (end < l || r < start) return 0;

//         if (l <= start && end <= r) {
//             return tree[node].sum;
//         }

//         int mid = (start + end) / 2;
//         return query(node*2, start, mid, l, r)
//              + query(node*2+1, mid+1, end, l, r);
//     }

//     void update(int node, int start, int end, int l, int r, int x) {
//         propagate(node, start, end);
//         if (end < l || r < start) return;

//         if (l <= start && end <= r) {
//             lazy[node] ^= x;
//             propagate(node, start, end);
//             return;
//         }

//         int mid = (start + end) / 2;
//         update(node*2, start, mid, l, r, x);
//         update(node*2+1, mid+1, end, l, r, x);
//         tree[node] = Pair(tree[node*2], tree[node*2+1]);
//     }
// };

// void solve() {
//     int n;
//     cin >> n;

//     SegTreeLzy tree;
//     tree.init(n);

//     for (int i = 0; i < n; i++) {
//         cin >> tree.ar[i];
//     }

//     tree.build(1, 0, n-1);

//     int q;
//     cin >> q;

//     while (q--) {
//         int t, l, r;
//         cin >> t >> l >> r;
//         l--; r--;

//         if (t == 1) {
//             cout << tree.query(1, 0, n-1, l, r) << endl;
//         } else {
//             int x;
//             cin >> x;
//             tree.update(1, 0, n-1, l, r, x);
//         }
//     }
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     int t = 1;
//     while (t--) solve();

//     return 0;
// }




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
#define srt_3(v)       sort(v.begin(),v.end())
#define mxe_3(v)       *max_element(v.begin(),v.end())
#define mne_3(v)       *min_element(v.begin(),v.end())
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>

const int N = 200005;
const int MAXB = 20;

int st[4*N][MAXB];
int lazy[4*N];

void build(int node, int l, int r, vi &a){
    if(l == r){
        for(int b = 0; b < MAXB; b++){
            st[node][b] = (a[l] >> b) & 1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(node<<1, l, mid, a);
    build(node<<1|1, mid+1, r, a);
    for(int b = 0; b < MAXB; b++){
        st[node][b] = st[node<<1][b] + st[node<<1|1][b];
    }
}

void apply(int node, int l, int r, int x){
    for(int b = 0; b < MAXB; b++){
        if(x & (1LL << b)){
            st[node][b] = (r - l + 1) - st[node][b];
        }
    }
    lazy[node] ^= x;
}

void push(int node, int l, int r){
    if(lazy[node] == 0) return;
    int mid = (l + r) >> 1;
    apply(node<<1, l, mid, lazy[node]);
    apply(node<<1|1, mid+1, r, lazy[node]);
    lazy[node] = 0;
}

int query(int node, int l, int r, int ql, int qr){
    if(r < ql || l > qr) return 0;
    if(ql <= l && r <= qr){
        int res = 0;
        for(int b = 0; b < MAXB; b++){
            res += st[node][b] * (1LL << b);
        }
        return res;
    }
    push(node, l, r);
    int mid = (l + r) >> 1;
    return query(node<<1, l, mid, ql, qr) +
           query(node<<1|1, mid+1, r, ql, qr);
}

void update(int node, int l, int r, int ql, int qr, int x){
    if(r < ql || l > qr) return;
    if(ql <= l && r <= qr){
        apply(node, l, r, x);
        return;
    }
    push(node, l, r);
    int mid = (l + r) >> 1;
    update(node<<1, l, mid, ql, qr, x);
    update(node<<1|1, mid+1, r, ql, qr, x);
    for(int b = 0; b < MAXB; b++){
        st[node][b] = st[node<<1][b] + st[node<<1|1][b];
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    fr_3(i, n) cin >> a[i];

    build(1, 0, n-1, a);

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n-1, l, r) << endl;
        }else{
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            update(1, 0, n-1, l, r, x);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    while(t--) solve();

    return 0;
}
