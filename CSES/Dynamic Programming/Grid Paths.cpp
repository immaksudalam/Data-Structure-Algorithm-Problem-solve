#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<char> >&grid, int i, int j, int n, vector<vector<int> >&dp){
	if(i>= n || j>= n || grid[i][j]=='*') return 0;
	if(i== n-1 && j == n-1) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = (solve(grid, i+1, j, n, dp) + solve(grid, i, j+1, n, dp))%1000000007;
}
int main()
{
	int n; cin>>n;
	vector<vector<char> >grid(n, vector<char>(n));
	vector<vector<int> >dp(n, vector<int>(n, -1));
	for(int i=0; i<n; i++)
	   for(int j=0; j<n; j++) cin>>grid[i][j];
	cout<<solve(grid, 0, 0, n, dp);
}
