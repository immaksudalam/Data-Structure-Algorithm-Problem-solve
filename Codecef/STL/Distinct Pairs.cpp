#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int in;
    vector<pair<int, int> >a,b;
    for(int i=0; i<n; i++){
        cin>>in;
        a.push_back({in,i});
    }
    for(int i=0; i<m; i++){
        cin>>in;
        b.push_back({in,i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<m; i++) cout<<a[0].second <<" "<<b[i].second<<endl;
    for(int i=1; i<n; i++) cout<<a[i].second <<" "<<b[m-1].second<<endl;

}
