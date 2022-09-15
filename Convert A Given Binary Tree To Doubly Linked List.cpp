#include <bits/stdc++.h> 
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
void solve (BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head, BinaryTreeNode<int>* &prev)
{
    if (root == NULL)
        return;
    
    solve (root -> left, head, prev);
    
    if (prev == NULL) head = root;
    else
    {
        root -> left = prev;
        prev -> right = root;
    }
    prev = root;
    
    solve (root -> right, head, prev);
}



BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    
    BinaryTreeNode <int> *prev = NULL, *head = NULL;
    solve (root, head, prev);
    return head;
    
    
}


