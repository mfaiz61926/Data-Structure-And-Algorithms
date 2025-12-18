#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> seg;
    int n;
    string s;

    void buildSegmentTree(int i, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        buildSegmentTree(2*i+1, l, mid, arr);
        buildSegmentTree(2*i+2, mid+1, r, arr);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    void update(int i, int l, int r, int idx, int val) {
        if (l == r) {
            seg[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2*i+1, l, mid, idx, val);
        else
            update(2*i+2, mid+1, r, idx, val);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return seg[i];
        int mid = (l + r) / 2;
        return query(2*i+1, l, mid, ql, qr) +
               query(2*i+2, mid+1, r, ql, qr);
    }

    vector<int> minDeletions(string s_, vector<vector<int>>& queries) {
        s = s_;
        n = s.size();

        // build bad array
        vector<int> bad(n, 0);
        for (int i = 1; i < n; i++) {
            bad[i] = (s[i] == s[i-1]);
        }

        seg.assign(4*n, 0);
        buildSegmentTree(0, 0, n-1, bad);

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int j = q[1];
                // flip character
                s[j] = (s[j] == 'A' ? 'B' : 'A');

                // update bad[j]
                if (j > 0) {
                    int val = (s[j] == s[j-1]);
                    update(0, 0, n-1, j, val);
                }

                // update bad[j+1]
                if (j+1 < n) {
                    int val = (s[j+1] == s[j]);
                    update(0, 0, n-1, j+1, val);
                }
            } 
            else {
                int l = q[1], r = q[2];
                if (l == r) ans.push_back(0);
                else ans.push_back(query(0, 0, n-1, l+1, r));
            }
        }

        return ans;
    }
};
