class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    vector<int>ans;
    bool dfs(int node){
        vis[node]=1;
        for(auto child: adj[node]){
            if(vis[child]==1) return false;
            if(vis[child]==0){
                if(!dfs(child)) return false;
            }
        }
        ans.push_back(node);
        vis[node]=2;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        adj.resize(n+1);
        vis.resize(n+1, 0);
        ans.clear();
        
        for(int i=0; i<p.size(); i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                if(!dfs(i)){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
