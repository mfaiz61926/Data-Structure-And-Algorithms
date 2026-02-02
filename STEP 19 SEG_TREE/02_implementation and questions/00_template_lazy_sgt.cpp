#include <bits/stdc++.h>
using namespace std;



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
        st[node] = (st[2 * node + 1] + st[2 * node + 2]);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            st[node] += lazy[node] * (end - start + 1);  // apply pending addition
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
            st[node] += val * (end - start + 1);
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);
        st[node] = (st[2 * node + 1] + st[2 * node + 2]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return 0;  // no overlap

        push(node, start, end);  // apply pending updates

        if (l <= start && end <= r) return st[node];  // total overlap

        int mid = (start + end) / 2;
        return 
            query(2 * node + 1, start, mid, l, r) +
            query(2 * node + 2, mid + 1, end, l, r);
        
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

int main()
{
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	// cout << v.size();

	SegTreeLzy tree;

	tree.init(v.size());

	tree.build(v);

	cout << tree.query(0, 4) << '\n';

	tree.update(0, 1, 10);

	cout << tree.query(0, 4) << '\n';

	return 0;
}