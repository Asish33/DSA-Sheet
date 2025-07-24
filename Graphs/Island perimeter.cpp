class Solution {
public:
    int ans = 0;
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& visited) {
        int n = grid.size(), m = grid[0].size();
        if (row > grid.size() || col > grid[0].size())
            return;
        visited[row][col] = 1;
        ans += 4;
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int delr = row + delx[i];
            int delc = col + dely[i];
            if (delr >= 0 && delr < n && delc >= 0 && delc < m &&
                grid[delr][delc] == 1) {
                if (visited[delr][delc] == 1) {
                    ans = ans - 2;
                }
                if (visited[delr][delc] == 0) {
                    dfs(delr, delc, grid, visited);
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    dfs(i, j, grid, visited);
                    break;
                }
            }
        }
        return ans;
    }
};
