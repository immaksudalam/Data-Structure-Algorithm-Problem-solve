#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>graph;
vector<int>vis;
stack<int>recursionStack;
vector<bool>rsFlag;

bool dfs(int src){
    vis[src] = 1;
    recursionStack.push(src);
    rsFlag[src] = 1;

    for(auto it:graph[src]){
        if(!vis[it]){
            if(dfs(it)) return true;
        }
        if(rsFlag[it]){
            recursionStack.push(it);
            return true;
        }
    }
    recursionStack.pop();
    rsFlag[src] = false;

    return false;
}
void isCycle(){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i)) break;
        }
    }
}
int main()
{
    cin>>n>>m;
    graph.resize(n+1);
    vis.resize(n+1);
    rsFlag.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    isCycle();

    if(recursionStack.empty()){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>ans;
        int temp = recursionStack.top();
        while(!recursionStack.empty()){
            ans.push_back(recursionStack.top());
            recursionStack.pop();
            if(ans.back() == temp && ans.size() != 1) 
                break;
        }
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }
}
