#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x;
	cin>>n>>x;
	vector<int>prices(n), pages(n);
	for(int i=0; i<n; i++) cin>>prices[i];
	for(int i=0; i<n; i++) cin>>pages[i];
	vector<vector<int> >dp(n+1, vector<int>(x+1, 0));
	for(int i=0; i<=x; i++) if(i>= prices[0]) dp[0][i] = pages[0];
	for(int i=1; i<n; i++){
		for(int j=0; j<=x; j++){
			int buy = -1e8;
			int notbuy = dp[i-1][j];
			if(prices[i]<= j){
				buy = pages[i] + dp[i-1][j - prices[i]];
			}
		   dp[i][j] = max(notbuy, buy);
		}
	}
	cout<<dp[n-1][x]<<endl;
}
