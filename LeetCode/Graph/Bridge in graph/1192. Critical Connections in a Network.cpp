class Solution {
public:
    
    vector<vector<int>> ans;
    
    void dfs(int node,int parent , vector<int>& vis , vector<int>& tin , vector<int>& low ,int& timer, vector<vector<int>>& adj){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto it : adj[node]){
            if(it == parent){
                continue;
            }
            if(!vis[it]){
                dfs(it , node , vis , tin , low , timer , adj);
                low[node] =min(low[it] , low[node]); 
                if(low[it] > tin[node]){
                    ans.push_back({node , it});
                }
            }
            else{
                 low[node] = min(low[node] , tin[it]);   
                }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int>> adj(n );
        for(int i = 0 ; i < c.size() ; i++){
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
		// To check for visited nodes in dfs
        vector<int> vis(n , 0) ;
		
		// Time of insertion for a given node
        vector<int> tin(n , 0) ;
		
		//Lowest time of insertion
		vector<int> low(n ,0);
		
		
        int timer = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i ,-1 , vis , tin , low ,timer , adj);
            }
        }
        
        return ans;
    }
};
