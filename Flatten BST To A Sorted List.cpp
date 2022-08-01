/************************************************************

    Following is the Binary Tree node structure
    
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

void inorder (TreeNode <int>* root, vector <int> &ans ){
    if (root == NULL)
        return;
    
    inorder (root -> left, ans);
    ans.push_back(root -> data);
    inorder (root -> right, ans);
  
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
  
        vector <int> ans;
        inorder (root, ans);
    int n = ans.size();
    
    TreeNode<int>* curr = new TreeNode<int>(ans[0]);
    TreeNode<int>* newRoot = curr;
    
    for (int i = 1; i < n; i++){
         TreeNode<int>* temp = new TreeNode<int>(ans[i]);
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
      
    }

    // Step for last node 
    curr -> left = NULL;
    curr -> right = NULL;
    
    
    return newRoot;
    
}

// Space Complexity - O(N)
// Time Complexity - O(N)
