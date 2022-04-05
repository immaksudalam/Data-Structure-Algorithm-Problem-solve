class Solution {
public:
    int dp[101][101];
    int ans = 0;
    int helper(vector<vector<int>>&grid, int i, int j){
        if(i == grid.size()-1 && j==grid[0].size()-1 && grid[i][j]==0) return 1;
        if(i>= grid.size() || j>= grid[0].size()) return 0;
        if(grid[i][j] == 1) return 0;
        if(dp[i][j]) return dp[i][j];
        
        return dp[i][j] = helper(grid, i+1, j) + helper(grid, i, j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i=0; i<101; i++)
            for(int j=0; j<101; j++) dp[i][j] = 0;
        return helper(obstacleGrid, 0, 0);
    }
};
