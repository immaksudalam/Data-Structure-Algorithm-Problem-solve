class Solution {
public:
    void helper(vector<vector<int>>&image, int sr, int sc, int newColor, int m, int n, int source){
        if(sr<0 || sr>=m || sc<0 || sc>=n) return;
        if(image[sr][sc] != source) return;
        
        image[sr][sc]=newColor;
        
        helper(image, sr-1, sc, newColor, m, n, source);
        helper(image, sr+1, sc, newColor, m, n, source);
        helper(image, sr, sc-1, newColor, m, n, source);
        helper(image, sr, sc+1, newColor, m, n, source);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int m = image.size();
       int n = image[0].size();
       if(image.size()==0) return image;
       if(image[sr][sc]==newColor) return image;
       helper(image, sr, sc, newColor, m, n, image[sr][sc]);
        
       return image;
    }
};
