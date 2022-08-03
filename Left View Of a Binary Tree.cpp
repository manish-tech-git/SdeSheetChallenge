// *************************************************** USING LEVEL ORDER *********************************************

vector<int> leftView(Node *root)
{
    
    vector <int> ans;
    queue <Node* > q;
    
    if (root == NULL) return ans;
    
    q.push(root);
    
    while (!q.empty())
    {
        int size = q.size();
      // storing the data before traversing further left and right.
        ans.push_back (q.front() -> data);
        while (size--)
        {
            Node* temp = q.front();
            q.pop();
            
            if (temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
        
    }
    
    return ans;
   
}


// ********************************************************* USING RECURSION *********************************************

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
void printLeftView(TreeNode<int> *root, vector <int> &ans, int level)
{
    if(root == NULL) return ;
    
  
  // as the vector size increases then level will be increased
    if(level == ans.size()){
        ans.push_back(root -> data);
    }
    
    printLeftView(root -> left, ans, level+1);
    printLeftView(root -> right, ans, level +1);
    
    
    
}

vector<int> getLeftView(TreeNode<int> *root)
{
    
    
    vector <int> ans;
    printLeftView(root , ans,0);
    return ans;
}



// Time Complexity -> O(N)
// Space Complexity -> O(N)

