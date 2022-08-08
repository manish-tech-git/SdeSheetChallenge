
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

void mirrorTree(BinaryTreeNode<int> *root) {
    
    if (root == NULL)
        return ;
    
  // store the left value of the tree
    BinaryTreeNode<int> * temp = root -> left;
    
    root -> left = root -> right;
    root -> right = temp;
    
    mirrorTree (root -> left);
    mirrorTree (root -> right);
    
    
}




