#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (1LL<<61)
int main()
{
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>>adj(n+1, vector<ll>(n+1, INF));
    for (int i = 1; i <= n; ++i) adj[i][i] = 0;
    for(int i=1; i<=m; i++){
        int u, v;
        ll c;
        cin>>u>>v>>c;
        adj[u][v]=min(adj[u][v], c);
        adj[v][u] = min(adj[v][u], c);
    }
    for(int k=1; k<=n; k++)
      for(int i=1; i<=n; i++)
         for(int j=1; j<=n; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    while(q--){
        int u, v;
        cin>>u>>v;
        if(adj[u][v]==INF) cout<<-1<<endl;
        else cout<<adj[u][v]<<endl;
    }
}
