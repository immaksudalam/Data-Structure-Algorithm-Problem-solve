class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<int>cost(n+1);
       vector<int>vis(n+1);
       vector<vector<pair<int, int>>>adj(n+1);
        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int c = times[i][2];
            adj[u].push_back({v, c});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});
        while(!pq.empty()){
            int c = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node])continue;
            
            vis[node]=1;
            cost[node]=c;
            for(auto child: adj[node]){
                int curnode = child.first;
                int curc = child.second;
                if(vis[curnode])continue;
                pq.push({c + curc, curnode});
            }
        }
        for(int i=1; i<=n; i++) if(vis[i] == 0) return -1;
        int maxi=0;
        for(auto it: cost) maxi=max(maxi, it);
        return maxi;
    }
};
