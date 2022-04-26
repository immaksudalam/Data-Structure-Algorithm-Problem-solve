#include <bits/stdc++.h>
using namespace std;
int ways;
const int N = 1e6+6, mod = 1e9 + 7;
int dp[N];
int solve(int target){
	if(target == 0){
		return 1;
	}
	if (dp[target] != -1) return dp[target];
	int sum = 0;
	for(int i=1; i<=6; i++){
		if(target - i >= 0){ 
			sum += solve(target - i);
			sum %= mod;
		}
	}
	return dp[target] = sum;
}
int main()
{
	int n;
	cin>>n;
	memset(dp, -1, sizeof dp);
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		int sum =0;
		for(int j=1; j<=6; j++){
			if(i - j >= 0){ 
			sum += dp[i-j];
			sum %= mod;
       	}
       	dp[i] = sum;
    	}
	}
	cout<<dp[n]<<endl;
}
