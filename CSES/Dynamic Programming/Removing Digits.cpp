#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin>>n;
	vector<int>dp(n+1);
	dp[0] = 0;
	for(int i=1; i<10; i++)dp[i]=1;
	for(int i=10; i<=n; i++){
		int x = i;
		dp[i] = 100000007;
		while(x){
			int last = x%10;
			dp[i] = min(dp[i], 1 + dp[i - last]);
			x/=10;
		}
	}
	cout<<dp[n]<<endl;
