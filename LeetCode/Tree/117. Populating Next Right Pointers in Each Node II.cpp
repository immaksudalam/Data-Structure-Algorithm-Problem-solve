/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node *root){
        if(root == NULL) return;
        
        if(root->left){
            if(root->right) root->left->next = root->right;
            else{
                Node *temp = root->next;  // We'll try to go for rightmost node on same level which have left or right
                while(temp){
                    if(temp->left || temp->right){
                        if(temp -> left) root->left->next = temp->left;
                        else root->left->next = temp->right;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
        
        if(root->right && root->next){
            Node *temp = root->next;
            
            while(temp){
                if(temp->left || temp->right){
                    if(temp->left) root->right->next = temp->left;
                    else root->right->next = temp->right;
                    break;
                }
                temp = temp->next;
            }
        }
        
        dfs(root->right);
        
        dfs(root->left);
    }
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        
        
        dfs(root); // Call right child first because we have to complete right side first
        // Then only we'll be able to fill the left side of root
        
        return root;
    }
};
