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
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
      vector <int> ans;
 int level = 1;
    queue <BinaryTreeNode<int>*> q;
    q.push(root);
    if(root == NULL)
        return ans;
    
    while(!q.empty())
    {
        int size = q.size();
        vector <int> temp;
        for(int i= 0; i < size; i++){
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        temp.push_back(node -> data);
        if(node -> left)
            q.push(node-> left);
        if(node -> right)
            q.push(node-> right);
            
        }
        if(level%2 == 0)
            reverse(temp.begin(), temp.end());
        
        for (int i = 0; i< size; i++)
            ans.push_back(temp[i]);
       
        level =! level;
        
    }
       
    
    return ans;
    
}
