class Solution {
public:
    int parent[100000];
    int rank[100000] = {0};
    
    void make_set(int x){
       parent[x] = x;
    }
    int findParent(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
   void Union(int x, int y){
        int a = findParent(x);
        int b = findParent(y);
        
        if(rank[a]>= rank[b]){
            rank[a]++;
            parent[b] = a;
        }
        else{
            rank[b]++;
            parent[a] = b;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt = 0;
        vector<int>v(n+1, 0);
        for(int i=0; i<n; i++) make_set(i);
        
        for(int i=0; i<connections.size(); i++){            
            if(findParent(connections[i][0]) != findParent(connections[i][1])){
                Union(connections[i][0], connections[i][1]);
            }
            else{
                cnt++;
            }
        }
        
        set<int>s;
        //here we are counting the no of parents which is the no of components in the graph
        //if the freeconnections >= no of (connected_components-1) then (connected_components-1) is the ans
        //because in order to join n components the minimum no of cables needed are n-1
        
        for(int i=0; i<n; i++){
            s.insert(findParent(i));
        }
        if(cnt >= s.size()-1){
            return s.size() - 1;
        }
        else return -1;
        
    }
};
