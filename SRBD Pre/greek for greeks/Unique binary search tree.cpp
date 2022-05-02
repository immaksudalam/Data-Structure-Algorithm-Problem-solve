class Solution {
public:
    int solve(int n, vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        int total = 0;
        for(int i=1; i<=n; i++){
            total += solve(i-1, dp)*solve(n-i, dp);
        }
        return dp[n] = total;
    }
    int numTrees(int n) {
       vector<int>dp(200, -1);
       return solve(n, dp);
    }
};
