#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<int>&h, int i, vector<ll>&dp){
    if(i == h.size()-1) return 0;
    if(dp[i] != -1) return dp[i];
    ll onejump = abs(h[i]-h[i+1]) + solve(h, i+1, dp);
    ll twojump = 1e8;
    if(i+2 <h.size()) 
       twojump = abs(h[i]-h[i+2]) + solve(h, i+2, dp);
    return dp[i] = min(onejump, twojump);
}
int main()
{
    int n; cin>>n;
    vector<int>h(n);
    for(int i=0; i<n; i++) cin>>h[i];
    vector<ll>dp(n+1, -1);
    cout<< solve(h, 0, dp);
}
