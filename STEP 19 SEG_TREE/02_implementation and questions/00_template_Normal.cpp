#include <bits/stdc++.h>
using namespace std;
           
struct seg_tree {
    vector<int> seg;
    int n;
    
    seg_tree (int _n) : n(_n) {
        seg.resize(4*n);
    }
    
    void update (int pos, int val, int l = 0, int r = -1, int i = 0) {
        if (r == -1) r += n;
        if (l == r) {
            seg[i] = val;
            return;
        }
        int m = (l+r) >> 1;
        if (m >= pos) update (pos, val, l, m, i*2+1);
        else update (pos, val, m+1, r, i*2+2);
        seg[i] = max (seg[i*2+1], seg[i*2+2]);
    }
    
    int query (int x, int y, int l = 0, int r = -1, int i = 0) {
        if (r == -1) r += n;
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return seg[i];
        int m = (l+r) >> 1;
        return max (query(x, y, l, m, i*2+1), query (x, y, m+1, r, i*2+2));
    }
};

