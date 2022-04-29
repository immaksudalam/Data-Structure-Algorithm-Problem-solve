/*
  You are given the following:

  An integer N
  An integer X
  An integer y
  An array A of  elements N
  An array B of  elements N
  Find the number of pairs of (i, j) such that:
  (A[i]^B[i])&X = (A[i]^B[i])&Y
  where ^ represents bitwise XOR operator and & represents bitwise AND operator.
  0<=i, j<N
  
  (A[i]^B[j])&X = (A[i]^B[j])&Y
  => (A[i]&X)^(B[j]&X) = (A[i]&Y)^(B[j]&Y)
  =>(A[i]&X)^(B[j]&X) ^ (A[i]&Y)^(B[j]&Y) = 0
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t; cin>>t;
    while(t--){
        ll x, y, n;
        cin>>n>>x>>y;
        map<ll, ll>mp;
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            ll res = (a&x)^(a&y);
            mp[res]++;
        }
        ll ans = 0;
        for(int i=0; i<n; i++){
            ll b;
            cin>>b;
            ll res = (b&x)^(b&y);
            ans += mp[res];
        }
        cout<<ans<<endl;
    }
}
