/*There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps
from  ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair
or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

Memorization Process:
*/

#include <bits/stdc++.h>
int solve(int n, vector<int>&heights, vector<int>&dp){
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];
	int left = solve(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
	int right = INT_MAX;
	if(n > 1) right = solve(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
	
	return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
	vector<int> dp(n, -1);
     return solve(n-1, heights, dp);
}

//Tebulation Process

#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
	int dp[n];
	dp[0] = 0;
	for(int i=1; i<n; i++){
		int left = dp[i-1] + abs(heights[i] - heights[i-1]);
		int right = INT_MAX;
		if(i>1) right= dp[i-2] + abs(heights[i] - heights[i-2]);
		
		dp[i] = min(left, right);
	}
	return dp[n-1];
}
