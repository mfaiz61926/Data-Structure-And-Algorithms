struct SegTree {
public:
 
    SegTree (int _n) : n (_n) {
        tree.resize(4*n, 1e9);
    }
    
    int query (int x, int y) {
        return query (x, y, 0, n-1, 0);
    }
    
    void update (int ind, int val) {
        update (ind, val, 0, n-1, 0);
    }
 
private:
    
    vector<int> tree;
    int n;
    
    int query (int x, int y, int l, int r, int i) {
        if (r < x || l > y) return 1e9;
        if (l >= x && r <= y) return tree[i];
        
        int m = (l+r) >> 1;
        return min(
            query (x, y, l, m, i*2+1),
            query (x, y, m+1, r, i*2+2)
        );
    }
    
    void update (int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree[i] = val;
            return;
        }
        
        int m = (l+r) >> 1;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);
        
        tree[i] = min(tree[i*2+1], tree[i*2+2]);
    }
};


class Solution {
    
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    vector<int> longest_match;

    void AmmendLongestMatch (const string& word, const string& target) {
        string s = word + "$" + target;
        vector<int> z = z_function(s);
        
        for (int i = 0; i < target.length(); i ++) {
            longest_match[i] = max (longest_match[i], z[i+word.length()+1]);
        }
    }
    
public:
    int minValidStrings(vector<string>& words, string target) {
        longest_match.clear();
        longest_match.resize(target.length(), 0);
        
        for (auto w: words) AmmendLongestMatch (w, target);
        
        int n = target.size();
        SegTree max_len_tree(n+1);
        max_len_tree.update(n, 0);
                
        for (int j = n-1; j >= 0; j --) {
            int len = longest_match[j];
            if (len == 0) continue;
            
            int max_len = 1 + max_len_tree.query (j+1, j+len);
            max_len_tree.update (j, max_len);      
        }
        
        int ans = max_len_tree.query(0, 0);
        if (ans == 1e9) ans = -1;
        return ans;
    }
};

/*
#define pii pair<int, int>
#define F first
#define S second

const int N = 5e4+1;
const int P = 31;
const int M = 1e9+7;

const int INF = 1e9;

typedef long long int ll;

class Solution {
    
    vector<ll> p_pow;
    vector<ll> inv_p_pow;
    
    // a^b % M
    ll FastPower (ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b&1) ans = (ans * a) % M;
            a = (a*a) % M;
            b /= 2;
        }
        return ans;
    }
    
    void ComputePower() {
        if (!p_pow.empty()) return;
        
        p_pow.resize(N, 1);
        for (int i = 1; i < N; i ++)
            p_pow[i] = (p_pow[i-1] * P) % M;
        
        inv_p_pow.resize(N, 1);
        
        inv_p_pow[N-1] = FastPower (p_pow[N-1], M-2);
        for (int i = N-2; i > 0; i --)
            inv_p_pow[i] = (inv_p_pow[i+1] * P) % M;
    }
    
    vector<ll> HashIt (const string& s) {
        int S = s.size();
        vector<ll> prefix_hash(S+1, 0);

        for (int i = 1; i <= S; i++) {
            ll cur = (p_pow[i] * (s[i-1]-'a'+1)) % M;
            prefix_hash[i] = (prefix_hash[i-1] + cur) % M;
        }
        return prefix_hash;
    }
    
    inline ll HashOfRange (int l, int r, vector<ll>& prefix_hash) {        
        ll hash = (prefix_hash[r] - prefix_hash[l-1] + M) % M;
        return (hash * inv_p_pow[l-1]) % M;
    }
    
    int LongestMatching (int st, vector<ll>& prefix_hash_target, unordered_map<int, int>& hash_and_len) {
        int l = st, r = prefix_hash_target.size() - 1;
        
        while (l < r) {
            int m = (l+r) >> 1;
            int hash = HashOfRange (st, m+1, prefix_hash_target);
            
            auto it = hash_and_len.find(hash);
            if (it == hash_and_len.end()) r = m;
            else l = m+1;
        }
        
        int len = r - st + 1;
        int hash = HashOfRange (st, l, prefix_hash_target);
        if (hash_and_len.find(hash) == hash_and_len.end()) len--;
        return len;
    }
    
public:
    int minValidStrings(vector<string>& words, string target) {
        ComputePower();
        
        unordered_map<int, int> hash_and_len;
        for (auto w : words) {
            vector<ll> hash = HashIt(w);
            for (int l = 1; l < hash.size(); l ++) hash_and_len[hash[l]] = l;
        }
        
        int n = target.size();
        SegTree max_len_tree(n+2);
        max_len_tree.update(n+1, 0);
        
        vector<ll> prefix_hash_target = HashIt(target);
        
        for (int j = n; j > 0; j --) {
            int len = LongestMatching (j, prefix_hash_target, hash_and_len);
            if (len == 0) continue;
            
            int max_len = 1 + max_len_tree.query (j+1, j+len);
            max_len_tree.update (j, max_len);            
        }
        
        int ans = max_len_tree.query(1, 1);
        if (ans == 1e9) ans = -1;
        return ans;
    }
};
*/