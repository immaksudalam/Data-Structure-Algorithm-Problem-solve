class Solution {
public:
    void dfs(vector<vector<int>>&isConnected, vector<vector<int>>&visited, int i){
       
        for(int k = 0; k<isConnected[i].size(); k++){
            if(isConnected[i][k] == 1 && visited[i][k] == 0){
               visited[i][k] = 1; 
                dfs(isConnected, visited, k);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans =0;
        int n = isConnected.size();
        vector<vector<int>> visited(n, vector<int>(n));
        for(int i =0; i<n; i++)
            for(int j=0; j<n; j++){
                if(!isConnected[i][j]) visited[i][j] = 1;
                else visited[i][j] = 0;
            }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0){
                    ans++;
                    visited[i][j] = 1;
                    dfs(isConnected, visited, i);
                }
            }
        return ans;
    }
};
