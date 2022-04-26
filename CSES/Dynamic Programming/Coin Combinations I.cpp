#include <bits/stdc++.h>
using namespace std;
 
int dp[1000001];
int main()
{
	int mod=1000000007;
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, target;
	cin>>n>>target;
	vector<int>nums(n);
	dp[0] = 1;
	for(int i=0; i<n; i++) cin>>nums[i];
	
	for(int i=1; i<=target; i++){
		int sum = 0;
		for(int j = 0; j<n; j++){
			if(nums[j]<= i){
				sum += dp[i - nums[j]];
				sum %=mod;
			}
		}
		dp[i] = sum;
	}
	cout <<dp[target]<<endl;
}
