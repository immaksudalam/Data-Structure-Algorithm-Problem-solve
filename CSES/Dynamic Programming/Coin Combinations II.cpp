#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, target;
	cin>>n>>target;
	vector<int>nums(n);
	for(int i=0; i<n; i++) cin>>nums[i];
	vector<vector<int> >dp(n, vector<int>(target+1, 0));
	for(int i=0; i<=target; i++) if(i%nums[0] == 0) dp[0][i] = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<=target; j++){
				long notpic = dp[i-1][j];
				long pic = 0;
				if(nums[i]<=j){
					pic = dp[i][j- nums[i]];
				}
				dp[i][j] = (pic + notpic)%1000000007;
		}
	}
	cout<<dp[n-1][target]<<endl;
}
