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





Node* lca(Node* root ,int n1 ,int n2 )
    {
        
        if (root == NULL)
            return NULL;
            
        if (root -> data == n1 || root -> data == n2)
            return root;
        
        
        Node* left = lca (root -> left, n1, n2);
        Node* right = lca (root -> right, n1, n2);
        
        if (left and right)
            return root;
            
        else if(left)
            return left;
        
        else
            return right;

    }
