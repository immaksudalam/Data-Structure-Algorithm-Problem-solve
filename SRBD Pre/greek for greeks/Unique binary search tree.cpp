class Solution
{
    public:
    int mod = 1e9+7;
    long long solve(int n, vector<long long>&dp){
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        long long total = 0;
        for(int i=1; i<=n; i++){
            total = (total%mod) + ((solve(i-1, dp)%mod)*solve(n-i, dp)%mod)%mod;
            total%=mod;
        }
        return dp[n] = total;
    }
    int numTrees(int n) 
    {
        vector<long long>dp(n+2, -1);
        return solve(n, dp);
    }
