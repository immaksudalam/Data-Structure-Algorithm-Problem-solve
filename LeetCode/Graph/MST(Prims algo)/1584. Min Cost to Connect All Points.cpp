class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j)continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, dist});
            }
        }
        vector<int>cost(n+1);
        vector<int>vis(n+1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});
        int minCost = 0;
        while(!pq.empty()){
            int curdis = pq.top().first;
            int curnode = pq.top().second;
            pq.pop();
            if(vis[curnode])continue;
            vis[curnode]=1;
            cost[curnode]=curdis;
            minCost += curdis;
            for(auto child:adj[curnode]){
                int n = child.first;
                int d = child.second;
                if(vis[n]) continue;
                pq.push({d, n});
            }
        }
        return minCost;
    }
};
