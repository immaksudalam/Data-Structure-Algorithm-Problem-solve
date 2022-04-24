class Solution {
public:
    vector<int>vis, color;
    bool bfs(vector<vector<int>>&adj, int node){
        for(int i=node; i<adj.size(); i++){
            if(vis[i]) continue;
            color[i]=1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto child:adj[u]){
                    if(!vis[child]){
                        vis[child]=1;
                        color[child] = 1- color[u];
                        q.push(child);
                    }
                    if(color[u]==color[child]) return false;
                }
                
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(int i=0; i<dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.resize(n+1, 0);
        color.resize(n+1);
        return bfs(adj, 0);
    }
};
