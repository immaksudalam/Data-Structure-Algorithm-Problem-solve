#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool finddif(int c, ll mid, vector<ll> &v){
    ll left= -1;
    for(int i=0; i<v.size(); i++){
        if(c==0)break;
        if((v[i]-left)>=mid || left == -1){
            left=v[i];
            c--;
        }
    }
    if(c==0) return true;
    else return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n, c;
    cin>>n>>c;
    vector<ll>v(n);
    ll maxi = 0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(v[i] > maxi) maxi = v[i];
    }
    sort(v.begin(), v.end());
    ll l =0, r = 1e18;
    while(l <= r){
        ll mid = (l + r)/2;
        if(finddif(c, mid, v)) l = mid+1;
        else r = mid-1;
    }
     cout<<l-1<<endl;
    }
}
