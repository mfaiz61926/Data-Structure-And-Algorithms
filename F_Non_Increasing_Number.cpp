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

struct dps {
    int len;
    int rem;
    int last_digit;
    
    bool operator>(const dps& other) const {
        if (len != other.len) return len > other.len;
        return false; 
    }
};
class STree{        
private:

    // [IMPORTANT]  CHANGE this function as required. 
    int defaultVal=INT_MAX;
    vector<int> tree,lazy;
    int n;
    
    // [IMPORTANT] CHANGE this function as required.
    void pushDown(int v,int tl, int tr){    // if your current node had some changes and it's there in the lazy vector i.e. 
    // lazy[v] that means they weren't propagated to it's children .... .


        // this block is responsible for adding the values to both the left and right children.
        // the limits of these children are from tl to tmid & tmid+1,tl
        int tmid=(tl+tr)>>1;
        // the below is an example for adding a value to all nodes in the range 
        // and utilising the tree for minimum in the range
        tree[v*2]+=lazy[v];
        tree[v*2+1]+=lazy[v];
        lazy[v*2]+=lazy[v];         // take a note that you made some changes that haven't been passed on to your children . 
        lazy[v*2+1]+=lazy[v];           

        //once the updates are pushed to the children the parent can get rid of the update!
        lazy[v]=0;  // my responsibility is completely I've told the changes to my children.. now it's their headache!!!!1  
    }


    // [IMPORTANT] CHANGE this function as required.
    void combine(int v){  
        tree[v]=min(tree[v<<1],tree[v<<1|1]);
    }
    
    int query(int v, int tl, int tr, int l, int r) {      
        if (tr <tl) return defaultVal;
        if(tl>r || tr<l)    return defaultVal;       // invalid indices tried!
        if (l <= tl && r >= tr) return tree[v];     // the current segment completely belongs to the answer
        int tm = (tl + tr)>>1;
        pushDown(v,tl,tr);
        combine(v);

        // [IMPORTANT] CHANGE this code below as required.
        return min(query(v<<1, tl, tm, l, r)  , query(v<<1|1, tm+1, tr, l, r));
    }
    void buildTree(vector<int>& a,int tl, int tr,int v=1){  // builds up the tree starting from the root.
        if(tl>tr) return;
        if(tl==tr){
            tree[v]=a[tl];
            return;
        }
        int mid=(tl+tr)>>1;
        buildTree(a,tl,mid,v<<1);
        buildTree(a,mid+1,tr,v<<1|1);
        combine(v);
    }
    void update(int l,int r,int val,int v,int tl,int tr){
        if(tl>tr) return;
        if(tl>r || tr<l)  return;     //not in the current range
        
        if(tl>=l && tr<=r){        // [IMPORTANT] CHANGE the code below as required.
        // if the subtree is completely inside the range then update the current node ... 
        // also make sure your children can get this info in the future if and when they need it ...
            tree[v]+=val;   // update the value! 
            lazy[v]+=val;   // this is just for reference for the children and not for the current node as your current node is already updated!   
            return;         // return;
        }
        pushDown(v,tl,tr);          // notifying my children of the changes (if any! )
        int tmid=(tl+tr)>>1;
        update(l,r,val,v<<1,tl,tmid);
        update(l,r,val,v<<1|1,tmid+1,tr);
        combine(v);
    }
public:
    STree(vector<int>& vec){
        n=vec.size();
        tree.assign(n<<2,defaultVal);       // all nodes initially have default values 
        lazy.assign(n<<2,0);
        buildTree(vec,0,n-1);
    }

    int query(int l,int r){             // query in the range l to r.
        return query(1,0,n-1,l,r);
    }
    void update(int idx,int val){       // this is overloaded for point updates
        update(idx,idx,val,1,0,n-1);
    }
    void update(int l,int r,int val){     
        update(l,r,val,1,0,n-1);
    }
};
class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        iota(begin(parent), end(parent), 0);
    }
    
    int getParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }

    void join(int x, int y) {
        x = getParent(x);
        y = getParent(y);
        if (size[x] > size[y])
            swap(x, y);
        if (x == y) return;
        parent[x] = y;
        size[y] += size[x];
    }

    int getSize(int x) {
        return size[x] = size[getParent(x)];
    }
};
void solve() {
    int n;
    cin >> n;
    
    if (n % 10 == 0 && n != 10) {
        cout << -1 << '\n';
        return;
    }
    
    vector<vector<int>> prev_rem(n, vector<int>(10, -1));
    vector<vector<int>> prev_digit(n, vector<int>(10, -1));
    vector<vector<int>> added(n, vector<int>(10, -1));
    vector<vector<int>> length(n, vector<int>(10, 1e9));
    vector<vector<bool>> vis(n, vector<bool>(10, false));
    
    priority_queue<tuple<int, int, int>, 
                   vector<tuple<int, int, int>>, 
                   greater<tuple<int, int, int>>> pq;
    
    for (int d = 1; d <= 9; d++) {
        int rem = d % n;
        if (length[rem][d] > 1) {
            length[rem][d] = 1;
            prev_rem[rem][d] = -1;
            prev_digit[rem][d] = -1;
            added[rem][d] = d;
            pq.push({1, rem, d});
            
            if (rem == 0) {
                cout << d << '\n';
                return;
            }
        }
    }
    while (!pq.empty()) {
        auto &it  = pq.top();
        int len = get<0>(it);
        int rem = get<1>(it);
        int last_digit = get<2>(it);
        pq.pop();
        
        if (vis[rem][last_digit]) continue;
        vis[rem][last_digit] = true;
        
        if (rem == 0) {
            string result;
            int cr = rem, cd = last_digit;
            while (cr != -1) {
                result += char('0' + added[cr][cd]);
                int pr = prev_rem[cr][cd];
                int pd = prev_digit[cr][cd];
                cr = pr;
                cd = pd;
            }
            reverse(result.begin(), result.end());
            cout << result << '\n';
            return;
        }
        
        for (int nd = last_digit; nd <= 9; nd++) {
            int new_rem = (rem * 10 + nd) % n;
            if (!vis[new_rem][nd] && length[new_rem][nd] > len + 1) {
                length[new_rem][nd] = len + 1;
                prev_rem[new_rem][nd] = rem;
                prev_digit[new_rem][nd] = last_digit;
                added[new_rem][nd] = nd;
                pq.push({len + 1, new_rem, nd});
            }
        }
    }
    
    cout << -1 << '\n';
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