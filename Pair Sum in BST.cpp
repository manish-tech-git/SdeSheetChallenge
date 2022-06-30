/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>

void inorder (BinaryTreeNode<int> *root, vector <int> &ans)
{
    
    if(root == NULL ) return ;
    
    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);
    
    
}


bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    
    vector <int> ans;
    inorder(root, ans);
      int low = 0; 
     int high = ans.size()-1;
    
    while(low < high)
    {
        if(ans[low] + ans[high] == k){
            return true;
        }
        else if(ans[low] + ans[high] < k ){
            low++;
        }
        else{
            high--;
        }
    }
    return false;
    
    
}
