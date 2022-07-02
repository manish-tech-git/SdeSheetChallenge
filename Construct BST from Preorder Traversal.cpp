/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int> *buildBST(TreeNode <int>* &root , int ele)
{
    if (!root) {
       root = new TreeNode<int> (ele);
        return root;
    
    }
    if(root -> data > ele)
        root -> left = buildBST(root -> left, ele);
    
    else{
        root -> right = buildBST(root -> right, ele);
    }
    
    return root;
}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Construct a node 
    TreeNode<int> *root = NULL;
    
    for (auto x: preOrder){
        buildBST(root, x);
    }
    return root;
}

//Time Complexity - O(N^2)
//Space Complexity - O(N)




//Optimised Approach using using range (INT_MIN, INT_MAX - for the root Node) and it will updated on each and every element traversal

#include<bits/stdc++.h>

int construct_BST(vector<int> &preorder,int n,int pos,TreeNode <int>*curr,int left,int right)
    {
        if(pos==n || preorder[pos]<left || preorder[pos]>right) //Boundary case
            return pos;
        
        if(preorder[pos]<curr->data)     //Insert in left-subtree
        {
            curr->left = new TreeNode<int> (preorder[pos]);
            pos += 1;
            pos = construct_BST(preorder,n,pos,curr->left,left,curr->data-1);
        }
        
        if(pos==n || preorder[pos]<left || preorder[pos]>right)
            return pos;
        
        //Insert in right-subtree
        curr->right = new TreeNode<int>(preorder[pos]);
        pos += 1;
        pos = construct_BST(preorder,n,pos,curr->right,curr->data+1,right);
        return pos;
    }


TreeNode<int>* preOrderTree(vector<int> &preorder){
    // Write your code here.
    
     int n = preorder.size();
        if(n==0)
            return NULL;
        
        TreeNode<int>  *root = new TreeNode<int>(preorder[0]);
        if(n==1)
            return root;

        construct_BST(preorder,n,1,root,INT_MIN,INT_MAX);
        return root;
}

//Time Complexity - O(N)
//Space Complexity - O(N)

