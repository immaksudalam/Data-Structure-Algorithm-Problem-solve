#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>graph;
vector<int>vis;
vector<int>parent;
 
void dfs(int node){
    vis[node]=1;
    for(auto child:graph[node]){
        if(vis[child]==0){
            parent[child]=node;
            dfs(child);
        }
        else if(vis[child]==1){
            vector<int>path;
            parent[child]=-1;
            path.push_back(child);
            while(parent[node]!=-1){
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(node);
            reverse(path.begin(), path.end());
            cout<<path.size()<<endl;
            for(auto it:path)cout<<it<<" ";
            exit(0);
        }
    }
    vis[node]=2;
}
int main()
{
   cin>>n>>m;
   graph.resize(n+1);
   vis.resize(n+1);
   parent.resize(n+1);
   
   for(int i=0; i<m; i++){
       int u, v;
       cin>>u>>v;
       graph[u].push_back(v);
   }
   for(int i=1; i<=n; i++){
       if(vis[i])continue;
       dfs(i);
   }
   cout<<"IMPOSSIBLE"<<endl;
}
