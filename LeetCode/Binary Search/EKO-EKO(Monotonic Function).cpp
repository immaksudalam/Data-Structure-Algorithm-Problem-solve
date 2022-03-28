#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll func(ll mid, vector<ll>&v){
    ll res =0;
    int siz = v.size();
    for(int i=0; i<siz; i++){
        if(v[i]> mid)res += v[i]-mid;
    }
    return res;
}
int main()
{
    int n; cin>>n;
    ll m; cin>>m;
    int maxheight=0;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(v[i]> maxheight) maxheight = v[i];
    }
    ll l=0, r = maxheight;
    ll ans = -1;

    while(l <= r){
        ll mid = (l+r)/2;
        ll a = func(mid, v);
        if(func(mid, v) >= m) l = mid+1;
        else r = mid -1;
    }
    cout<<l-1<<endl;
}
