class Solution {
public:
    bool fun(vector<vector<char>>& board, int row, int col, string& word, int index, vector<vector<int>>& visited) {
        if (index == word.size()) return true;

        int n = board.size(), m = board[0].size();
        if (row < 0 || col < 0 || row >= n || col >= m) return false;
        if (visited[row][col] == 1 || board[row][col] != word[index]) return false;

        visited[row][col] = 1;

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, -1, 0, 1};

        for (int dir = 0; dir < 4; dir++) {
            int delrow = row + delx[dir];
            int delcol = col + dely[dir];
            if (fun(board, delrow, delcol, word, index + 1, visited))
                return true;
        }

        visited[row][col] = 0; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (fun(board, i, j, word, 0, visited))
                        return true;
                }
            }
        }
        return false;
    }
};
