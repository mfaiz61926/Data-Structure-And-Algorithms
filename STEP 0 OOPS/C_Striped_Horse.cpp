#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, W;
        cin >> N >> W;

        vector<ll> C(N);
        for (int i = 0; i < N; i++) cin >> C[i];

        int M = 2 * W;
        vector<ll> A(M, 0);

        // fill costs
        for (int i = 0; i < N; i++) {
            A[i] = C[i];
        }

        // initial window [0..W-1]
        ll cur = 0;
        for (int i = 0; i < W; i++) cur += A[i];

        ll ans = cur;

        // slide window for exactly 2W-1 more starts
        for (int start = 1; start < M; start++) {
            cur -= A[start - 1];
            cur += A[(start + W - 1) % M];
            ans = min(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}
