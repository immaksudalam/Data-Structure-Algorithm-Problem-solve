#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<int>&w, vector<int>&v, int pos, int W, vector<vector<ll> >&dp){
	if(pos == 0){
		if(w[0]<=W) return v[0];
		return 0;
	}
	if(dp[pos][W] != -1) return dp[pos][W];
	ll notpic = solve(w, v, pos-1, W, dp);
	ll pic = INT_MIN;
	if(w[pos] <= W) 
	    pic = v[pos] + solve(w, v, pos-1, W - w[pos], dp);
	return dp[pos][W] = max(pic, notpic);
}
int main()
{
	int n, W;
	cin>>n>>W;
	vector<int>w(n), v(n);
	for(int i=0; i<n; i++) cin>>w[i] >>v[i];
	vector<vector<ll> >dp(n, vector<ll>(W+1, -1));
	cout<<solve(w, v, n-1, W, dp);
}
