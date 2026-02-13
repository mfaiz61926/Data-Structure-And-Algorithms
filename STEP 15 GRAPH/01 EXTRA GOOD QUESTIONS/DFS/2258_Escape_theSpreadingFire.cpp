class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool isValid(int t, vector<vector<int>>&fireTime){
        int n = fireTime.size();
        int m = fireTime[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));

        queue<pair<int,int>>q;

        if(fireTime[0][0] <= t) return false;   

        q.push({0, 0});
        vis[0][0] = 1;

        while(!q.empty()){
            t++;
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nr = x + dr[k];
                    int nc = y + dc[k];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || fireTime[nr][nc] == -1) continue;

                    // u reached destination
                    if(nr == n-1 && nc == m - 1 && t <= fireTime[nr][nc]) return true;

                    if(t < fireTime[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
    
    void updateFireTime(vector<vector<int>>&fireTime, vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        int cur_time = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    fireTime[i][j] = cur_time;
                    vis[i][j] = 1;
                }
                else if(grid[i][j] == 2){
                    fireTime[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            cur_time++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop(); // bhool jata hu , sarkari hai

                for(int k = 0; k < 4; k++){
                    int nr = x + dr[k];
                    int nc = y + dc[k];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || fireTime[nr][nc] == -1) continue;

                    fireTime[nr][nc] = cur_time;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }

        }
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>fireTime(n, vector<int>(m, INT_MAX));
        updateFireTime(fireTime, grid);

        int ans = -1;
        int low = 0;
        int high = n * m + 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isValid(mid, fireTime)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return ans == m * n + 1 ? 1e9 : ans;
    }
};