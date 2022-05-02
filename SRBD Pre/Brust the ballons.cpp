class Solution {
public:
    int solve(int i, int j, vector<int>&ballon, vector<vector<int>>&dp){
        if(i> j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = -1e8;
        for(int ind = i; ind<=j; ind++){
            int points = ballon[i-1]*ballon[ind]*ballon[j+1] + solve(i, ind-1, ballon, dp)
                               + solve(ind+1, j, ballon, dp);
            maxi = max(maxi, points);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>ballon;
        ballon.push_back(1);
        for(int i=0; i<nums.size(); i++) ballon.push_back(nums[i]);
        ballon.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, ballon, dp);
    }
};
