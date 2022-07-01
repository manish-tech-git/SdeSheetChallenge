/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int height (BinaryTreeNode<int> *root)
{
    if(root == NULL) return 0;
    
    int ans = (max(height(root-> left),height( root -> right)) + 1);
    
    return ans;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root == NULL) return true;
    
    int l = height(root -> left);
    int r = height (root -> right);
    
    bool ans = ((abs(l -r) <= 1) && isBalancedBT(root -> left) && isBalancedBT(root -> right));
    
    return ans;
    
}


