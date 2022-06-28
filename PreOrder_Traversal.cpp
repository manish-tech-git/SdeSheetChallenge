/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

#include<bits/stdc++.h>

void PreOrder(vector <int> &ans, TreeNode* root){
   
    if(root == NULL)
        return ;
    
    ans.push_back(root -> data);
    PreOrder(ans, root -> left);
    
    PreOrder(ans, root -> right);
    
}


vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector <int> ans;
    PreOrder(ans, root);
    return ans;
}
