class Solution {
public:
    
    int helper(vector<int> &nums, int pos, vector<int> &dp){
        if(pos >= nums.size()-1) return 0;
        
        if(dp[pos] != -1) return dp[pos];
        
        int minJump = INT_MAX-1000;
        for(int i = pos +1; i<= pos+nums[pos]; i++)
            minJump = min(minJump, 1 + helper(nums, i, dp));
        
        return dp[pos] = minJump;
    }
    int jump(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n, -1);

       return helper(nums, 0, dp);
    }
};
