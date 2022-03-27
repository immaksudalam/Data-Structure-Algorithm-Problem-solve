/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* find(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == p) return p;
        if(root == q) return q;
        if((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val))
            return root;
        if(p->val < root->val && q->val < root->val) 
            return find(root->left, p, q);
        else return find(root->right, p, q);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};
