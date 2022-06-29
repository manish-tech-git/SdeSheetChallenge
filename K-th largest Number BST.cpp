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
#include<bits/stdc++.h>
void inorder (TreeNode <int>*root,vector <int> &ans)
{
    if(root == NULL) return ;
    
    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);
    
    
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector <int> ans;
    inorder(root , ans);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if(ans.size()-i == k)
            return ans[i];
    }
    return -1;
}


//Time Complexity worst case - O(n)
