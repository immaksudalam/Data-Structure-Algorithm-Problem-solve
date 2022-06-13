class Solution {
public:
    void solve(TreeNode* root, int cur, int &res){
        if(!root) return;
        
        if(root->val >= cur) res++;
        
        solve(root->left, max(cur, root->val), res);
        solve(root->right, max(cur, root->val), res);
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        solve(root, INT_MIN, res);
        
        return res;
    }
};
