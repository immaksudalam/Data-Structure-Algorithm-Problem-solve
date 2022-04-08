#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pii;
#define mx 3001
vector<pii>v[mx];
int cost[mx];
bool visited[mx];
struct node{
    int u, cost;
};
bool operator <(node a, node b){
    return a.cost > b.cost;
}

int prims(int src){
    for(int i=0; i<mx; i++){
        cost[i] = 1e9;
        visited[i] = 0;
    }
    cost[src] = 0;
    node temp;
    temp.u = src;
    temp.cost = 0;
    priority_queue<node> pq;
    pq.push(temp);
    int totalcost =0;
    
    while(!pq.empty()){
        node cur = pq.top();
        pq.pop();
        
        if(visited[cur.u]) continue;
        visited[cur.u] = true;
        totalcost += cur.cost;
        
        for(int i=0; i<v[cur.u].size(); i++){
            node t;
            t.u = v[cur.u][i].first;
            t.cost = v[cur.u][i].second;
            pq.push(t);
            cost[t.u] = t.cost;
        } 
    }
    return totalcost;
}
int main()
{
    int node, edge;
    cin>>node>>edge;
    
    for(int i=0; i<edge; i++){
        int a, b, w;
        cin>>a>>b>>w;
        a--, b--;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }    
    cout<<prims(0)<<endl;
}
