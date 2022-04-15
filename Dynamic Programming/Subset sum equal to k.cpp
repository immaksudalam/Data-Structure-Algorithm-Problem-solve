#include <bits/stdc++.h>
int n, target, k;
int dp[1001][1001];
bool solve(vector<int> &arr, int pos, int cursum){
    if(pos == n){
        if(cursum == target) return true;
        return false;
    }
    if(cursum == target) return  true;
    if(dp[pos][cursum] != -1) return dp[pos][cursum];
    if(dp[pos][cursum] != -1) return dp[pos][cursum];
    if(solve(arr, pos+1, cursum + arr[pos])) return true;
    
    if(solve(arr, pos+1, cursum)) return true;
    return  dp[pos][cursum] = false;
}
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}
