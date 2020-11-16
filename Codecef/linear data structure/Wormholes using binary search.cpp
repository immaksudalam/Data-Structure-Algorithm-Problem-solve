#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x,y; cin>>n>>x>>y;
    int a,b;
    vector<pair<int, int> >v;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    vector<int>vx, vy;
    for(int i=0; i<x; i++){
        cin>>a;
        vx.push_back(a);
    }
    for(int i=0; i<y; i++){
        cin>>a;
        vy.push_back(a);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        int start=-1, endi=-1;
        int l = 0, r = x-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(vx[mid]<=v[i].first){
                start=mid;
                l=mid+1;
            }
            else r = mid-1;

        }
        l = 0;
        r = y-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(vy[mid]>= v[i].second){
                endi = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        if(start==-1 || endi == -1)continue;
        ans = min(ans , vy[endi]- vx[start]+1);
    }
    cout << ans <<endl;
}
