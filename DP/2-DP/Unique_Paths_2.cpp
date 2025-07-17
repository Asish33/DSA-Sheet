//recursive solutions.
// same as unique paths added wall extra.
class Solution {
public:
    int fun(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0)
            return 0;
        if (grid[row][col] == 1)
            return 0;
        if (row == 0 && col == 0)
            return 1;
        int up = fun(grid, row - 1, col);
        int left = fun(grid, row, col - 1);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        return fun(obstacleGrid, row - 1, col - 1);
    }
};
