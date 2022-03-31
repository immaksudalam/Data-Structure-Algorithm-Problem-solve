class Solution {
public:
    int dfs(vector<vector<int>>&grid, int i, int j, int zero){
        if(i<0 || i>=grid.size() || j<0 || j>= grid[i].size() || grid[i][j] == -1)
            return 0;
        if(grid[i][j] == 2){
            if(zero == -1) return 1;
            else return 0;
        }
        grid[i][j] = -1;
        zero--;
        
        int total = dfs(grid, i+1, j, zero) +
              dfs(grid, i-1, j, zero) + 
              dfs(grid, i, j+1, zero) +
              dfs(grid, i, j-1, zero);
        
        grid[i][j] = 0;
        zero++;
        return total;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0, c, r;
        
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0)zero++;
                if(grid[i][j] == 1)r=i, c=j;
            }
        
         return dfs(grid, r, c, zero);
    }
    
    
   
};
