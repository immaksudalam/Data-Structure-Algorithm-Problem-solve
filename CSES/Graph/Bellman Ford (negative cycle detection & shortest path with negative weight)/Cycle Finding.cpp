#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (1LL<<60)
struct edge{
    int u, v;
    ll w;
};
int main()
{
    int n, m;
    cin>>n>>m;
    vector<edge>edges(m+1);
    for(int i=1; i<=m; i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    vector<ll>dist(n+1, INF);
    vector<int>parent(n+1, -1);
    int x ;
    for(int i=0; i<n; i++){
        x = -1;
        for(auto e: edges){
            if(dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }
    if(x==-1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++) x = parent[x];
        vector<int>cycle;
        for (int v = x; ; v = parent[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        for (auto &x : cycle) cout << x << " ";
        cout << '\n';
    }
}
