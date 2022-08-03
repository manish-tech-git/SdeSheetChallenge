// ************************************************* USING LEVEL ORDER (ITERATION) *********************************************

vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector <int> ans;
    if (root == NULL) 
        return ans;
    queue < BinaryTreeNode<int>* > q;
    
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        ans.push_back(q.front() -> data);
        while (size--)
        {
            BinaryTreeNode<int>* temp = q.front();
            q.pop();
            
          
          // JUST TRAVERSE RIGHT SUBTREE FIRST 
            if (temp -> right)
                q.push (temp -> right);
          
          // THEN LEFT SUBTREE
            if (temp -> left)
                q.push(temp -> left);
        }
        
    }
    return ans;
}


// Time Complexity -> O(N)
// Space Complexity -> O(N)
