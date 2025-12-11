// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& grid, int count = 0) { //BEST SOLUTION
//         unordered_map<int,set<int>> st1, st2;
//         for (auto& p : grid) {
//             st1[p[0]].insert(p[1]);
//             st2[p[1]].insert(p[0]);
//         }
        
//         for (auto& p : grid) {
//             auto& it1 = st1[p[0]];
//             auto& it2 = st2[p[1]];
//             auto[downy, uph] = it1.equal_range(p[1]);
//             auto[downx, upx] = it2.equal_range(p[0]);
//             bool up = downy != it1.begin();
//             bool down = uph != it1.end();
//             bool left = downx != it2.begin();
//             bool right = upx != it2.end();
//             if (up && down && left && right) ++count;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        if (buildings.empty()) return 0;

        unordered_map<int, vector<int>> mp;
        unordered_map<int, vector<int>> mpp;

        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            mp[x].push_back(y);
            mpp[y].push_back(x);
        }

        for (auto& i : mp) {
            sort(i.second.begin(), i.second.end());
        }
        for (auto& i : mpp) {
            sort(i.second.begin(), i.second.end());
        }

        int cnt = 0;

        for (auto num : buildings) {
            int x = num[0];
            int y = num[1];

            vector<int>& row = mp[x];
            bool l = !row.empty() && row.front() < y;

            bool r = !row.empty() && row.back() > y;

            vector<int>& col = mpp[y];
            bool a = !col.empty() && col.front() < x;

            bool b = !col.empty() && col.back() > x;

            if (l && r && a && b) {
                cnt++;
            }
        }

        return cnt;

    }
};