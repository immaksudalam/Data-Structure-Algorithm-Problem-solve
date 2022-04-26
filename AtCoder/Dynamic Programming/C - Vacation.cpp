#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<vector<ll>>&point, int pos, int last, vector<vector<ll>>&dp){
	if(pos == 0){
		ll maxi = 0;
		for(int i=0; i<3; i++)
		   if(i != last)
		      maxi = max(maxi, point[0][i]);
		return maxi;
	}
	if(dp[pos][last] != -1) return dp[pos][last];
	ll maxi = 0;
	for(int i=0; i<3; i++){
		if(i != last){
			maxi = max(maxi, point[pos][i] + solve(point, pos-1, i, dp));
		}
	}
	return dp[pos][last] = maxi;
}
int main()
{
	int n;
	cin>>n;
	vector<vector<ll>>dp(n, vector<ll>(4,-1));
	vector<vector<ll>>point(n, vector<ll>(3));
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++) cin>> point[i][j];
	}
	cout<<solve(point, n-1, 3, dp);
}
