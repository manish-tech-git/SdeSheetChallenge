/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
long long int solve(TreeNode<int> *root, long long int &ans) {
    if(!root) return 0;
    
    long long int l = solve(root->left, ans);
    long long int r = solve(root->right, ans);
    ans = max(ans, l+r+root->val);
    
    return max(l, r)+root->val;
}

long long int findMaxSumPath(TreeNode<int> *root) {
    if(!root) return -1;
    if(!root->left || !root->right) return -1;
    
    long long int ans = 0;
    solve(root, ans);
    return ans;
}
