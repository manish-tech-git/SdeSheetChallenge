/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	
    //Base condition 
    if(root == NULL)
        return -1;
    
    if(root -> data == x || root -> data == y)
        return root -> data;
    
    //Calling left node of tree
    int l = lowestCommonAncestor (root -> left, x, y);
    //Calling Right node of
    int r = lowestCommonAncestor (root -> right, x, y);
    
    if(l == -1)
        return r;
    
    if(r == -1)
        return l;
    
    else{
        return root-> data;
    }
    
    
}

// Time Complexity - O(N)
// Space Complexity - O(N)
