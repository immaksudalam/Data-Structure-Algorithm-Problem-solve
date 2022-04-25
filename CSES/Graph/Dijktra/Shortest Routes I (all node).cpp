#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, ll> > >adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        adj[u].push_back({v, c});
    }
    vector<ll>cost(n+1, 1LL<<61);
    vector<int>vis(n+1, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
    pq.push({0, 1});
    while(!pq.empty()){
        ll curcost = pq.top().first;
        int curnode = pq.top().second;
        pq.pop();
        if(vis[curnode])continue;
        vis[curnode]=1;
        cost[curnode]=curcost;
        for(auto child: adj[curnode]){
            if(vis[child.first])continue;
            pq.push({curcost +child.second , child.first});
        }
 
    }
    for(int i =1; i<=n; i++)cout<<cost[i]<<" ";
}
