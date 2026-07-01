#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1), B(N + 1), D(N + 1);
    vector<vector<int>> events(M + 1);

    vector<int> cnt(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> D[i] >> B[i];
        events[D[i]].push_back(i);

        if (D[i] == 1)
            cnt[B[i]]++;
        else
            cnt[A[i]]++;
    }

    int distinct = 0;
    for (int c = 1; c <= N; c++)
        if (cnt[c] > 0) distinct++;

    for (int day = 1; day <= M; day++) {
        if (day > 1) {
            for (int id : events[day]) {
                int from = A[id];
                int to = B[id];

                if (from == to) continue;

                cnt[from]--;
                if (cnt[from] == 0) distinct--;

                if (cnt[to] == 0) distinct++;
                cnt[to]++;
            }
        }
        cout << distinct << '\n';
    }

    return 0;
}