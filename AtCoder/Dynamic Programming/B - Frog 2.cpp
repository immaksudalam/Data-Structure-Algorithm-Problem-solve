#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<ll>&h, int pos, int &k, vector<ll>&dp){
	if(pos == 0) return 0;
	if(dp[pos] != -1) return dp[pos];
	ll minStep = 1e10;
	for(int i=1; i<=k; i++){
		if(pos - i>= 0)
		  minStep = min(minStep, abs(h[pos] - h[pos-i]) + solve(h, pos-i, k, dp));
	}
	return dp[pos]=minStep;
}
int main()
{
	int n, k;
	cin>>n>>k;
	vector<ll>h(n);
	for(int i=0; i<n; i++) cin>>h[i];
	vector<ll>dp(n, -1);
	cout<<solve(h, n-1, k, dp)<<endl;
}
