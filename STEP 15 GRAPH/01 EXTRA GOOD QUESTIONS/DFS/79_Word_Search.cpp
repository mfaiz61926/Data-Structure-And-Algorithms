#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int i, int j, int k, vector<vector<char>>& board, string& word) {
        if(board[i][j] != word[k]) return false;
        if (k == word.size() - 1)
            return true;

        char temp = board[i][j];
        board[i][j] = '#'; // marked visited

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int p = 0; p < 4; p++) {
            int nr = i + dr[p];
            int nc = j + dc[p];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] == word[k+1]) {
                if (dfs(nr, nc, k + 1, board, word)) {
                    return true;
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};