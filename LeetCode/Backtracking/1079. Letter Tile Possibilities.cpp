class Solution {
public:
    set<string> result;
    map<int, int>flag;
   
    void solve(string &tiles, string &cur){
        for(int i=0; i<tiles.size(); i++){
            if(flag[i] == 0){
                cur.push_back(tiles[i]);
                flag[i]=1;
                result.insert(cur);
                
                solve(tiles, cur);
                
                flag[i]=0;
                cur.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        string cur="";
        solve(tiles, cur);
        
        return result.size();
    }
};
