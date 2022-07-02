/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
//Naive Approach


TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if (root == NULL) return NULL;
    
    if (root -> data == P -> data || root -> data == Q -> data)
        return root ;
    
    TreeNode <int> *l = LCAinaBST(root -> left, P, Q);
    TreeNode <int> *r = LCAinaBST(root -> right, P, Q);
    
    if( l == NULL)
        return r;
    else if(r == NULL)
        return l;
    else
        return root ;
    
    
}

// Time COmplexity - O(N)

//***************************************************************** Optimised Approach **************************************************************************

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    
    
    if(root == NULL) return NULL;
    
    int curr = root -> data;
    
    if(P -> data < curr && Q -> data < curr)
       return LCAinaBST(root -> left, P,Q);
    
    if(P -> data > curr && Q -> data > curr)
        return LCAinaBST (root -> right, P, Q);
    
    else
        return root ;
    
    
}

// TIme Complexity - O(Height of Tree) - OR O(H)


