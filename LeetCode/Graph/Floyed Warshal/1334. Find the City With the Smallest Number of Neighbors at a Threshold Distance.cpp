class Solution {
public:
    const int INF = 1e5;
    int findTheCity(int n, vector<vector<int>>& edges, int distance) {
        int dist[101][101];
        for(int i=0; i<101; i++)
            for(int j=0; j<101; j++){
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            
            dist[u][v] = d;
            dist[v][u] = d;
        }
        
        for(int k=0; k<101; k++)
            for(int i=0; i<101; i++)
                for(int j=0; j<101; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
        
       
        int cnt = 0;
        int ans;
        int counter = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] == 0 or dist[i][j] == INF) continue;
                if(dist[i][j] <= distance) cnt++;
            }
           
            if(cnt <= counter){
                ans = i;
                counter = cnt;
            }
            cnt = 0;
        }
        
        return ans;
    }
};
