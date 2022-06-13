class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int curlevel = 0;
        int cursum = 0;
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level != curlevel){
                cursum = 0;
                curlevel++;
            }
            
            cursum += cur->val;
            
            if(cur->left){
                q.push({cur->left, level+1});
            }
            if(cur->right){
                q.push({cur->right, level + 1});
            }
        }
        return cursum;
    }
};
