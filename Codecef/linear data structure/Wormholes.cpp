#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x, y;
    cin>>n>>x>>y;
    vector<pair<int, int> >v;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    vector<int>vx, vy;
    for(int i=0; i<x; i++){
        int a;
        cin>>a;
        vx.push_back(a);
    }
    for(int i=0; i<y; i++){
        int a;
        cin>>a;
        vy.push_back(a);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        int start, endi;
        start = lower_bound(vx.begin(), vx.end(), v[i].first)-vx.begin();
        if(v[i].first!=vx[start]) start--;
        endi = lower_bound(vy.begin(), vy.end(), v[i].second)- vy.begin();
        if(vy[endi]< v[i].second) continue;
        ans = min(ans, vy[endi]- vx[start]+1);
    }
    cout<<ans<<endl;
}
