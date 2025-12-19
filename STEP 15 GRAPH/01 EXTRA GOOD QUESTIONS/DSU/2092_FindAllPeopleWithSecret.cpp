class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;

        if (rankv[pa] < rankv[pb]) parent[pa] = pb;
        else if (rankv[pa] > rankv[pb]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rankv[pa]++;
        }
    }

    void reset(int x) {
        parent[x] = x;
        rankv[x] = 0;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        unite(0, firstPerson);

        int i = 0, m = meetings.size();

        while (i < m) {
            int time = meetings[i][2];
            vector<int> list;

            while (i < m && meetings[i][2] == time) {
                unite(meetings[i][0], meetings[i][1]);
                list.push_back(meetings[i][0]);
                list.push_back(meetings[i][1]);
                i++;
            }

            for (int p : list) {
                if (find(0) != find(p)) {
                    reset(p);
                }
            }
        }

        vector<int> ans;
        for (int p = 0; p < n; p++) {
            if (find(0) == find(p)) ans.push_back(p);
        }
        return ans;
    }
};