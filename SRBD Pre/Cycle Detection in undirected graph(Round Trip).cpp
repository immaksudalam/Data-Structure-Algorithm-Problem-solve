#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>p;
vector<int>vis;
 
void dfs(int node){
    vis[node] = 1;
    for(auto child: graph[node]){
        if(vis[child] == 0){
            p[child] = node;
            dfs(child);
        }
        else if(child != p[node]){
            vector<int>path;
            p[child] = -1;
            path.push_back(child);
            while(p[node] != -1){
                path.push_back(node);
                node = p[node];
            }
            path.push_back(node);
            reverse(path.begin(), path.end());
            cout<<path.size()<<endl;
            for(auto it:path)cout<<it<<" ";
            exit(0);
        }
    }
}
int main()
{
   int n, m;
   cin>>n>>m;
   graph.resize(n+1);
   p.resize(n+1);
   vis.resize(n+1);
   for(int i = 0; i<m; i++){
       int u, v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
   for(int i=1; i<=n; i++){
       if(vis[i])continue;
       dfs(i);
   }
   cout<<"IMPOSSIBLE"<<endl;
}
