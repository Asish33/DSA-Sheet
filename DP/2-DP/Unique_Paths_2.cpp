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

//memo solution with 2d dp array as it has 2 state variables
class Solution {
public:
    int fun(vector<vector<int>>& grid, int row, int col,
            vector<vector<int>>& dp) {
        if (row < 0 || col < 0)
            return 0;
        if (grid[row][col] == 1)
            return 0;
        if (row == 0 && col == 0)
            return 1;
        if (dp[row][col] != -1)
            return dp[row][col];
        int up = fun(grid, row - 1, col, dp);
        int left = fun(grid, row, col - 1, dp);
        return dp[row][col] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return fun(obstacleGrid, row - 1, col - 1, dp);
    }
};
