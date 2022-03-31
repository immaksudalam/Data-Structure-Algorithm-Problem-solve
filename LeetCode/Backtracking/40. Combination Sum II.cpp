class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>&candidates, vector<int>cur, int target, int pos){
        if(target <0) return;
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        
        for(int i = pos; i<candidates.size(); i++){
            cur.push_back(candidates[i]);
            helper(candidates, cur, target-candidates[i], i);
            
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur;
        helper(candidates, cur, target, 0);
        
        return ans;
    }
};
