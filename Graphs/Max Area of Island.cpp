class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& visited) {
        int n = grid.size(), m = grid[0].size();
        if (row < 0 || row > n || col < 0 || col > m)
            return 0;
        visited[row][col] = 1;
        int area = 1;
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int delrow = row + delx[i];
            int delcol = col + dely[i];
            if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m &&
                grid[delrow][delcol] == 1 && visited[delrow][delcol] == 0) {
                area += dfs(delrow, delcol, grid, visited);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int finalAns = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    finalAns = max(finalAns, dfs(i, j, grid, visited));
                }
            }
        }
        return finalAns;
    }
};
