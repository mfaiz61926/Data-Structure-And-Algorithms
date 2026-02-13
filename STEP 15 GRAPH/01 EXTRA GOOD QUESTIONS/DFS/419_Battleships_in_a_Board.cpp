class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&board){
        board[i][j] = 'F';
        int n = board.size();
        int m = board[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'X'){
                dfs(nr, nc, board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'X'){
                    cnt++;
                    dfs(i, j, board);
                }
            }
        }

        return cnt;
    }
};