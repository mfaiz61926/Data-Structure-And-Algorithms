/******************************************************************************

                              بسم الله الرحمان الرحيم
author:mconq(Mohd_Faiz)

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define endl "\n"

struct SegTreeLzy {
    int n;
    vector<int> st, lazy;

    void init(int _n) {
        n = _n;
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(int node, int start, int end, const vector<int> &v) {
        if (start == end) {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, v);
        build(2 * node + 2, mid + 1, end, v);
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            st[node] += lazy[node];  // apply pending addition
            if (start != end) {      // propagate to children
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);  // first apply pending updates

        if (start > r || end < l) return;  // no overlap

        if (l <= start && end <= r) {      // total overlap
            st[node] += val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return LLONG_MAX;  // no overlap

        push(node, start, end);  // apply pending updates

        if (l <= start && end <= r) return st[node];  // total overlap

        int mid = (start + end) / 2;
        return min(
            query(2 * node + 1, start, mid, l, r),
            query(2 * node + 2, mid + 1, end, l, r)
        );
    }


    void build(vector<int> &v) {
		build(0, 0, n - 1, v);
	}

    int query(int l, int r) {
		return query(0, 0, n - 1, l, r);
	}

	void update(int l, int r, int x) {
		update(0, 0, n - 1, l, r, x);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n,0);
   

    SegTreeLzy tree;
    tree.init(n);
    tree.build(v);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            tree.update(l, r - 1, x);  // convert [l,r) to [l,r-1]
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.query(l, r - 1) << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
