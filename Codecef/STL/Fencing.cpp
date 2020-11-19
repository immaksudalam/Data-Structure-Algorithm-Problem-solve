#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int ans = 4*k;
        int c1=0, r1 =0;
        vector <pair<int, int> >row, colum;
        for(int i=0; i<k; i++){
            int r, c; cin>>r>>c;
            row.push_back({r,c});
            colum.push_back({c, r});

        }
        sort(row.begin(), row.end());
        sort(colum.begin(), colum.end());
        for(int i=0; i<k-1; i++){
            if((row[i].first==row[i+1].first) && (row[i+1].second-row[i].second==1)) r1++;
        }
        for(int i=0; i<k-1; i++){
            if((colum[i].first == colum[i+1].first) &&(colum[i+1].second- colum[i].second==1))c1++;
        }
        ans -= 2*(r1+c1);
        cout<<ans<<endl;
    }

}
