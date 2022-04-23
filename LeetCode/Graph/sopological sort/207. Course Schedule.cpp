//cycle detection in directed graph
/*
 3 state 
 0 for unvisited
 1 for being visited (backage ditection) 
 2 for completely visited

*/

class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    bool dfs(int node){
        vis[node] = 1;
        for(auto child: adj[node]){
            if(vis[child]==1) return false; //backage
            if(vis[child]==0)
                if(!dfs(child)) return false;
        }
        vis[node]=2;
        
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
      adj.resize(n+1);  
      for(int i=0; i<p.size(); i++){
          adj[p[i][1]].push_back(p[i][0]);
      }
      vis.resize(n+1, 0);
      for(int i=0; i<n; i++){
          if(vis[i] == 0){
              if(!dfs(i)) return false;
          }
      }
      return true;
    }
};
