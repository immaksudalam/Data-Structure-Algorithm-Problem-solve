class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>&graph, vector<int>&cur, int source){
        if(source == graph.size()-1){
            cur.push_back(source);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        
        cur.push_back(source);
        
        for(int i=0; i<graph[source].size(); i++){
           dfs(graph, cur, graph[source][i]);
           
        }
        cur.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>cur;
        dfs(graph, cur, 0);
        
        return ans;
    }
};
