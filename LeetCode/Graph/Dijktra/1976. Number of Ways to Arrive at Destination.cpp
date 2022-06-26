using ll = long long;
class Solution {
public:
    const int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<ll, ll>>graph[n+1];
         for(int i=0; i<roads.size(); i++){
             ll u = roads[i][0];
             ll v = roads[i][1];
             ll t = roads[i][2];
             
             graph[u].push_back({v, t});
             graph[v].push_back({u, t});
         }
         vector<ll>dist(n+1, 1e18), cnt(n+1, 0);
         dist[0] = 0;
         cnt[0] = 1;
         priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>p;
         
         p.push({0, 0});
         while(!p.empty()){
            ll node = p.top().second;
            ll t    = p.top().first;
            p.pop();
            
            if(t != dist[node]) continue;
            for(auto child:graph[node]){
                ll v = child.first;
                ll len = child.second;
                if(dist[node] + len <= dist[v]){
                    if(dist[node] + len == dist[v]){
                       cnt[v] = (cnt[v] + cnt[node])%mod;
                    }
                    else{
                        dist[v] = dist[node] + len;
                        p.push({dist[v], v});
                        cnt[v] = cnt[node]%mod;
                    }
                }
            }
         }
         
         return cnt[n-1];
    }
};
