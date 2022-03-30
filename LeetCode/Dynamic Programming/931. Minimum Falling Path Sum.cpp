class Solution {
public:
    int dp[101][101];
    int helper(vector<vector<int>>&matrix, int i, int j){
        if(i == matrix.size()-1 && j>=0 && j<= matrix[i].size()-1) return matrix[i][j];
        if(j<0 || j>= matrix[i].size()) return 20000;
        if(dp[i][j]) return dp[i][j];
        return  dp[i][j] = matrix[i][j]+ min(helper(matrix, i+1, j), min(helper(matrix, i+1, j-1), helper(matrix, i+1, j+1)));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<matrix[0].size(); i++){
            ans = min(ans, helper(matrix, 0, i));
        }
        
        return ans;
    }
};
