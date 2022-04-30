#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> >&cost, int pos, int level, vector<int>&vis){
	if(level == cost.size()) return cost[pos][0];
	int ans = INT_MAX;
	vis[pos]=1;
	for(int i = 0; i<cost.size(); i++){
		if(vis[i]==0){
			vis[i]=1;
			ans = min(ans, cost[pos][i] + solve(cost, i, level+1, vis));
			vis[i]=0;
		}
	}
	vis[pos]=0;
	return ans;
	
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> >cost(n, vector<int>(n));
		for(int i=0; i<n; i++)
		  for(int j=0; j<n; j++) cin>>cost[i][j];
		vector<int>vis(n, 0);
		int ans = solve(cost, 0, 1, vis);
		cout<<ans<<endl;
	}
}
