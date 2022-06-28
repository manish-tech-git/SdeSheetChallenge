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

void PostOrder(vector <int> &ans, TreeNode* root){
   
    if(root == NULL)
        return ;
    
   
    PostOrder(ans, root -> left);
    PostOrder(ans, root -> right);
    ans.push_back(root -> data);
    
}


vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector <int> ans;
    PostOrder(ans, root);
    return ans;
}
