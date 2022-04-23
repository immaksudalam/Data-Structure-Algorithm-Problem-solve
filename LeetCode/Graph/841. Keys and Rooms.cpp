class Solution {
public:
    vector<vector<int>>e;
    vector<int>vis;
    void dfs(int node){
        vis[node]=1;
        for(auto child:e[node]){
            if(vis[child]) continue;
            else dfs(child);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        e.resize(n+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<rooms[i].size(); j++){
                e[i].push_back(rooms[i][j]);
            }
        }
        vis.resize(n+1, 0);
        dfs(0);
        for(int i=1; i<n; i++) if(!vis[i]) return false;
        return true;
    }
};
