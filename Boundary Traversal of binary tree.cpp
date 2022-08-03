class Solution {
public:

  
  // Traversing Left Part of Tree
    void traverseLeft (Node* root, vector <int> &ans){
        
        if ( (root == NULL )  || (root -> left == NULL && root -> right == NULL) )
            return;
            
        ans.push_back (root -> data);
        if (root -> left)
            traverseLeft (root -> left, ans);
        else
            traverseLeft (root -> right, ans);
        
    }
    
  
  // Traversing Leaf Nodes
    void traverseLeaf (Node* root, vector <int> &ans){
        
        // Base case
        if (root  == NULL)
            return;
            
        if (root -> left == NULL && root -> right == NULL){
            ans.push_back(root-> data);
            return;
        }
        
        
        traverseLeaf (root -> left, ans);
        traverseLeaf (root -> right, ans);
        
        
    }
    
    // Traversing Right Part of tree
    void traverseRight (Node* root, vector <int> &ans){
        //base case
         if ( (root == NULL )  || (root -> left == NULL && root -> right == NULL) )
            return;
            
            
        if (root -> right)
            traverseRight (root -> right, ans);
        else
            traverseRight(root -> left, ans);
            
        // before returning store the values
        ans.push_back(root -> data);
         
        
     }
    

    vector <int> boundary(Node *root)
    {
        
        vector <int> ans;
        if (root == NULL)
            return ans;
            
        ans.push_back (root -> data);
        
        // Left part print/store
        traverseLeft (root -> left, ans);
        
        // traverse leaf node
        
        // Leaf Subtree
        traverseLeaf (root -> left, ans);
        traverseLeaf (root -> right, ans);
        
        // traverse right Part
        
        traverseRight(root -> right, ans);
        
        return ans;
        
        
        
    }
};


