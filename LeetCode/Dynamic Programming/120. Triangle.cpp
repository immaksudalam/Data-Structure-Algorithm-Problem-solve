class Solution {
public:
    long long dp[201][201];
    long long helper(vector<vector<int>>&traingle,int i, int j, int sum){
        if(i< 0 || i>= traingle.size() || j<0 || j>=traingle[i].size()) return 3000;
        if(i==traingle.size()-1) return traingle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
 
        return dp[i][j] = min(helper(traingle, i+1, j, sum), helper(traingle, i+1, j+1, sum))  + traingle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0; i<201; i++)
            for(int j=0; j<201; j++)dp[i][j]=-1;
 
        return helper(triangle,0, 0,  0);
    }
};
