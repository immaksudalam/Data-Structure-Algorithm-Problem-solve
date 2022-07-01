
class Solution {
public:
    void solve(TreeNode* root, vector<int>&result, int level){
        if(!root) return;
        if(result.size() == level){
            result.push_back(root->val);
        }
        solve(root->right, result, level +1);
        solve(root->left, result, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        solve(root, result, 0);
        return result;
    }
};
