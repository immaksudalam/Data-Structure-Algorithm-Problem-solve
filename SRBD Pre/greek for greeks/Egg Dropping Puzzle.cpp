public:
    int solve(int eggs, int floors, vector<vector<int>>&dp){
        if(floors == 1 || floors == 0) return floors;
        if(eggs == 1 || eggs == 0) return floors;
        if(dp[eggs][floors] != -1) return dp[eggs][floors];
        int ans = INT_MAX;
        for(int currentFloor=1; currentFloor<=floors; currentFloor++){
            int temp = 1 + max(solve(eggs-1, currentFloor-1, dp),
            solve(eggs, floors - currentFloor, dp));
            ans = min(ans, temp);
        }
        return dp[eggs][floors]=ans;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(n, k, dp);
    }
