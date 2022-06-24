class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
      vector<pair<int, int>>tree[100000];
      
      for(int i=0; i<connections.size(); i++){
          tree[connections[i][0]].push_back({connections[i][1], 1});
          tree[connections[i][1]].push_back({connections[i][0], 0});
      }
     
      vector<int>vis(100000, 0);
      queue<int>p;
      int ans = 0;
      p.push(0);
      vis[0] = 1;
        while(!p.empty()){
            int u = p.front();
            p.pop();
            
            for(auto child: tree[u]){
                int v = child.first;
                bool f = child.second;
                
                if(vis[v]) continue;
                if(f) ans++;
                vis[v] = 1;
                p.push(v);
                
            }
        }
        return ans;
    }
};
