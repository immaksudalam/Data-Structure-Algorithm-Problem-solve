class Solution {
public:
    vector<vector<int>>ans;
    
    void helper(vector<int>&numbers, int pos, int k, vector<int>&cur){
        if(pos> numbers.size()) return;
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }
        
        for(int i=pos; i<numbers.size(); i++){
            cur.push_back(numbers[i]);
            helper(numbers, i+1, k, cur);
            
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<int>numbers(n);
        for(int i=0; i<n; i++) numbers[i] = i+1;
        helper(numbers, 0, k, cur);
        
        return ans;
    }
};
