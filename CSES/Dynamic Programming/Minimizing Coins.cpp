#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<int>&nums, int pos, int target, vector<vector<int> >&dp){
	if(pos == 0){
		if(target % nums[pos] == 0)
		   return target / nums[pos];
		else return 1e8;
	}
	if(dp[pos][target] != -1) return dp[pos][target];
	int notpic = solve(nums, pos-1, target, dp);
	int pic = 1e8;
	if(nums[pos]<= target){
		pic = 1 + solve(nums, pos, target - nums[pos], dp);
	}
	return dp[pos][target] = min(pic, notpic);
}
int main()
{
	int n, target;
	cin>>n>>target;
	vector<int>nums(n);
	for(int i=0; i<n; i++) cin>>nums[i];
	vector<vector<int> >dp(n, vector<int>(target+1, 0));
	for(int i=0; i<=target; i++){
		if(i % nums[0] == 0)  dp[0][i] = i / nums[0];
		else dp[0][i] = 1e9;
	}
	for(int i=1; i<n; i++){
		for(int tar = 0; tar <= target; tar++){
			int notpic = dp[i-1][tar];
			int pic = 1e9;
			if(nums[i]<=tar){
				pic = 1 + dp[i][tar - nums[i]];
			}
			dp[i][tar] = min(pic, notpic);
		}
	}
	if(dp[n-1][target] == 1e9)cout<<-1<<endl;
	else cout<<dp[n-1][target];
}
