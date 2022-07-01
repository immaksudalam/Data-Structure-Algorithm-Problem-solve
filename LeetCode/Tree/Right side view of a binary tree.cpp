struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

void solve(Node *root, vector<int>&result, int level){
    if(!root) return;
    if(result.size() == level){
        result.push_back(root->data);
    }
    solve(root->left, result, level + 1);
    solve(root->right, result, level + 1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int>result;
   solve(root, result, 0);
   return result;
}
