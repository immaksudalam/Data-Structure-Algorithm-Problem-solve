class Solution {
public:
    int helper(vector<vector<int>>&grid, int sr, int sc, int m, int n){
        if(sr<0 || sr>=m || sc<0 || sc>=n) return 0;
        if(grid[sr][sc] != 1) return 0;
        
        int ans =1;
        grid[sr][sc]=3;
        
        ans+= helper(grid, sr+1, sc, m, n);
        ans+= helper(grid, sr-1, sc, m, n);
        ans+= helper(grid, sr, sc+1, m, n);
        ans+= helper(grid, sr, sc-1, m, n);
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0; 
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int counter = 0;
                    int a = helper(grid, i, j, m, n);
                    ans = max(a, ans);
                }
            }
        
        return ans;
    }
};
