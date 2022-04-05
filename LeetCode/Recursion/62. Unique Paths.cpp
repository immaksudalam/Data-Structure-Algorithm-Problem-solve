class Solution {
public:
    long long dp[101][101];
    long long helper(int m, int n){
        if(n==1 || m==1) return 1;
        if(dp[m][n]) return dp[m][n];
        return dp[m][n] = helper(m, n-1) + helper(m-1, n);
    }
    int uniquePaths(int m, int n) {
        for(int i=0; i<101; i++)
            for(int j=0; j<101; j++) dp[i][j]=0;
        return helper(m, n);
    }
};
