class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int tot_cnt = 0;
        int rotten = 0;
        
        
        queue<pair<int,int>>q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != 0) tot_cnt++;
                
                if(mat[i][j] == 2) q.push({i, j});
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        int timer = 0;
        int cnt = 0;
        while(!q.empty()){
            
            int size = q.size();
            cnt += size;
            
            for(int i = 0; i < size; i++){
                auto it = q.front();
                
                int r = it.first;
                int c = it.second;
                q.pop();
                
                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] ==1){
                        mat[nr][nc] = 2; // mark them rotten or visited
                        q.push({nr, nc});
                    }
                }
                
            }
            if(!q.empty()) timer++;
            
        }
        if(cnt == tot_cnt) return timer;
        else return -1;
    }
};