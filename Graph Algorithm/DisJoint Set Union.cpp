#include <bits/stdc++.h>
using namespace std;
#define mx 100000
int parent[mx];
int rank[mx];

void make_set(int n){
    parent[n] = n;
    rank[n] = 1;
}

int findParent(int x){
    if(x == parent[x])
       return x;
    return parent[x] = findParent(parent[x]); // path compression o(4*n)
}

void union_set(int x, int y){
    int u = findParent(x);
    int v = findParent(y);
    
    if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else{
        parent[u] = v;
        rank[u]++;
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<=n; i++) make_set(i);
    while(m--){
        int x, y; 
        cin>>x>>y;
        union_set(x, y);
    }
    // a and b are the same set or not?
    int a, b; cin>>a>>b;
    if(findParent(a) == findParent(b))
         cout<<"They belong same set"<<endl;
    else cout<<"They belong different set"<<endl;
}
