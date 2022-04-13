#include <bits/stdc++.h>
using namespace std;

int n, m;
int start, finish;
vector<vector<int>>graph;
vector<int>vis;
vector<int>parent;

bool dfs(int src, int p){
    vis[src] = 1;
    parent[src] = p;

    for(auto it:graph[src]){
        if(!vis[it]){
            if(dfs(it, src)) return true;
        }
        else if(it != p){
            start = it;
            finish = src;
            return true;
        }
    }
    return false;
}
bool isCycle()
{
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i, -1)) return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    graph.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool ans = isCycle();
    if(!ans){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>ans;
        int temp = finish;
        ans.push_back(finish);
        while(temp != start){
            ans.push_back(parent[temp]);
            temp = parent[temp];
        }
        ans.push_back(finish);
        cout<<ans.size()<<endl;
        for(auto it:ans)cout<<it<<" ";
        cout<<endl;
    }


}
