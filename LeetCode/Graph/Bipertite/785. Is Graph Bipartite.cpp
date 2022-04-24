class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int src, vector<int>&vis, vector<int>&color){
        for(int i=src; i<graph.size(); i++){
            if(vis[i]) continue;
            vis[i] = 1;
            color[i] = 1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto it:graph[u]){
                    if(!vis[it]){
                        vis[it]=1;
                        color[it] = 1 - color[u];
                        q.push(it);
                    }
                    if(color[u] == color[it]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n+1, 0);
        vector<int>color(n+1);
        return bfs(graph, 0, vis, color);
    }
};
