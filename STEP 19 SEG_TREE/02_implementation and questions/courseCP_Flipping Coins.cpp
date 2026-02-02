#include<bits/stdc++.h>
using namespace std;


struct SegTreeLzy {
	int n;
	vector<int> st, lazy;

	void init(int _n) {
		this->n = _n; // n = _n is also corrct
		st.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
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
		// non overlapping case
		if (start > r || end < l) {
			return 0;
		}

		// lazy propagation / clear the lazy update
		if (lazy[node] != 0) {
			// pending updates
			// update the segment tree node
			st[node] = (end - start + 1) - st[node] ;    //did some updates here + with ^
			if (start != end) {
				// propagate the updated value
				lazy[2 * node + 1] ^= 1;                   //did some updates here + with ^
				lazy[2 * node + 2] ^= 1;                   //did some updates here + with ^
			}
			lazy[node] = 0;
		}

		// complete overlap
		if (start >= l && end <= r) {
			return st[node];
		}

		// partial case
		int mid = (start + end) / 2;

		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, end, l, r, 2 * node + 2);

		return q1 + q2;
	}

	void update(int start, int end, int node, int l, int r, int value) {
		// non overlapping case
		if (start > r || end < l) {
			return ;
		}

		// lazy propagation / clear the lazy update
		if (lazy[node] != 0) {
			// pending updates
			// update the segment tree node
			st[node] =  (end - start + 1) - st[node];   //did some updates here + with ^
			if (start != end) {
				// propagate the updated value
				lazy[2 * node + 1] ^= 1;              //did some updates here + with ^
				lazy[2 * node + 2] ^= 1;              //did some updates here + with ^
			}
			lazy[node] = 0;
		}

		// complete overlap
		if (start >= l && end <= r) {
			st[node] = (end - start + 1) - st[node];     //did some updates here + with ^
			if (start != end) {
				lazy[2 * node + 1] ^= 1;                //did some updates here + with ^
				lazy[2 * node + 2] ^= 1;                //did some updates here + with ^
			}
			return;
		}

		// partial case
		int mid = (start + end) / 2;

		update(start, mid, 2 * node + 1, l, r, value);

		update(mid + 1, end, 2 * node + 2, l, r, value);

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];    

		return;
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int l, int r, int x) {
		update(0, n - 1, 0, l, r, x);
	}
};
vector<int> solve(int n,int q, vector<vector<int>> query){
    vector<int>ans;
    
    vector<int>arr(n);
    for(int i = 0; i < n; i++) arr[i] = 0;
    
    SegTreeLzy tree;
    tree.init(n);
    tree.build(arr);
    
    for(auto & it : query){
        int t = it[0];
        int l = it[1];
        int r = it[2];
        
        if(t == 0){
            tree.update(l, r, 1);
        }
        else{
             ans.push_back(tree.query(l, r));
        }
    }
    return ans;
}