class Solution {
public:
    vector<vector<int>>ans;
    void solve(TreeNode* root, int &curSum, int &targetSum, vector<int>&cur){
        if(!root){
            return;
        }
        if(!root->left && !root->right && targetSum == curSum+root->val){
            cur.push_back(root->val);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        
        cur.push_back(root->val);
        curSum += root->val;
      
        solve(root->left, curSum, targetSum, cur);
        solve(root->right, curSum, targetSum, cur);
        
        cur.pop_back();
        curSum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int curSum = 0;
        vector<int>cur;
        solve(root, curSum, targetSum, cur);
        
        return ans;
    }
};
