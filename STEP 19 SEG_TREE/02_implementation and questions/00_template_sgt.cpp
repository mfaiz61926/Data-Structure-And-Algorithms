#include<bits/stdc++.h>
using namespace std;
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

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
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

int main()
{
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	// cout << v.size();

	SegTree tree;

	tree.init(v.size());

	tree.build(v);

	cout << tree.query(0, 4) << '\n';

	tree.update(4, 10);
    cout << tree.query(0, 4) << '\n';

	return 0;
}