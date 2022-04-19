class Solution {
public:
    void dfs(TreeNode* root, int val){
        if(root == NULL) return;
        if(val < root->val){
            if(!root->left){
                root->left = new TreeNode(val);
                return;
            }
            else dfs(root->left, val);
        }
        else{
            if(!root->right){
                root->right = new TreeNode(val);
                return;
            }
            else dfs(root->right, val);
        } 
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode* temp = root;
        dfs(root, val);
        return temp;
    }
};
