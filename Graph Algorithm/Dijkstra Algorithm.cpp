#include <bits/stdc++.h>
using namespace std;

vector<int> restore_path(int src, int lastNode, vector<int>&path){
    vector<int> v;
    
    for(int i= lastNode; i != src; i = path[i])
         v.push_back(i);
    v.push_back(src);
    
    reverse(v.begin(), v.end());
    
    return v;
}
int main()
{
    int node, edge;
    cin>>node>>edge;
    
    vector<pair<int, int> >graph[node+1];
    for(int i=0; i<edge; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt});
    }
    int source; cin>> source;
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    vector<int>dist(node+1, INT_MAX);
    dist[source] = 0;
    pq.push({0, source});
    vector<int>path(node+1);
    path[source] = -1;
    int LastVisit;
    while(!pq.empty()){
        int dis = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        LastVisit = u;
        
        for(auto it : graph[u]){
            int next = it.first;
            int nextDis = it.second;
            if(dist[next] > dist[u] + nextDis){
                dist[next] = dist[u] + nextDis;
                pq.push({dist[next], next});
                path[next] = u;
            }
        }
    }
    
    cout<<"Distance from source to "<<endl;
    for(int i=1; i<=node; i++) cout<<dist[i]<<" ";
    cout<<endl;
    
    vector<int> v = restore_path(source, LastVisit, path);
    
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}
