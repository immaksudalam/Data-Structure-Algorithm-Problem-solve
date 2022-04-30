#include <bits/stdc++.h>
using namespace std;
pair<int, int>office, home;
vector<pair<int, int>>customer;
int mini, n;
vector<int>vis;

int distance(pair<int, int>a, pair<int, int>b){
    return abs(a.first - b.first)+abs(a.second - b.second);
}
void solve(pair<int, int>now, int cost, int pos){
    if(pos == n){
        cost+= distance(now, home);
        mini = min(mini, cost);
        return;
    }
    for(int i=0; i<n; i++){
        if(vis[i]==0){
            vis[i]=1;
            solve(customer[i], cost + distance(now, customer[i]), pos+1);
            vis[i]=0;
        }
    }
}
int main()
{

    int t=10;
    for(int test = 1; test<=t; test++){
        mini = 1e8;
        cin>>n;
        customer.resize(n);
        cin>>office.first>>office.second;
        cin>>home.first>>home.second;
        for(int i=0; i<n; i++){
            cin>>customer[i].first;
            cin>>customer[i].second;
        }
        vis.resize(n, 0);
        solve(office, 0, 0);
        cout<<"# "<<test<<" "<<mini<<endl;
    }
}
