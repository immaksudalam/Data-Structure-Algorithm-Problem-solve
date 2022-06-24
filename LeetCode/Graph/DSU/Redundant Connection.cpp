class Solution {
public:
    int parent[1001];
    void makeSet(int n){
        parent[n] = n;
    }
    
    int findParent(int x){
        if(x == parent[x])
            return x;
        return parent[x] = findParent(parent[x]); //path Compression
    }
    
    bool Union(int x, int y){
        int u = findParent(x);
        int v = findParent(y);
        
        if(u == v){
            return 1;
        }
        else{
            parent[u] = v;
            return 0;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        fill(parent, parent+1000, 0);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            if(!parent[u]) makeSet(u);
            if(!parent[v]) makeSet(v);
            
            if(Union(u, v)) return {u, v};
        }
        return {};
    }
};
