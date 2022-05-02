#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<int>&ballon, vector<vector<int>>&dp, int n){
        if(i> j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = -1e8;
        for(int ind = i; ind<=j; ind++){
            int points;
            if(i==1 && j==n)
                points = ballon[ind] + solve(i, ind-1, ballon, dp, n) + solve(ind+1, j, ballon, dp, n);
            else points = ballon[i-1]*ballon[j+1] + solve(i, ind-1, ballon, dp, n) + solve(ind+1, j, ballon, dp, n);
            maxi = max(maxi, points);
        }
        return dp[i][j] = maxi;
    }
int main()
{
    int n;
    cin>>n;
    vector<int>ballon;
    ballon.push_back(1);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        ballon.push_back(a);
    }
    ballon.push_back(1);
    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    cout<<solve(1, n, ballon, dp, n);
}
