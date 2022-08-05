/*************************************************************
    
    Following is the Binary Tree node structure.
    
    class BinaryTreeNode {
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
#include<bits/stdc++.h>

void solve (BinaryTreeNode<int> *root, int k, vector <vector<int>> &ans, vector <int> &path)
{
    if (root == NULL) 
        return;
    
    path.push_back(root -> data);
    
    solve (root -> left, k, ans, path);
    solve (root -> right, k, ans, path);
    
    vector <int> temp;
    int sum = 0;
    for (int i = path.size()-1; i>=0; i--){
       sum += path[i];
        temp.insert (temp.begin(), path[i] );
        if(sum == k)
            ans.push_back(temp);
    }
    
     path.pop_back();
    return;
}

vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    vector <vector <int> > ans;
    vector <int> temp;
    solve (root, k, ans, temp);
    return ans;
}


// Time Complexity: O(n*h*h)  , as maximum size of path vector can be h 
// Space Complexity: O(h)
