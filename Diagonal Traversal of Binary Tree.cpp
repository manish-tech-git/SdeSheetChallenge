// ******************************** Diagonal Traversal of Binary tree *****************************************

vector<int> diagonal(Node *root)
{

    vector <int> ans; 
    queue <Node*> q;
    if (root == NULL)
        return ans;
        
    q.push(root);
    
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
      
        while (temp)
        {
            
          // if left node is present then we have to push into the queue
            if (temp -> left)   q.push(temp -> left);
              
          // otherwise simply push the values into vector
          ans.push_back(temp -> data);
                temp = temp -> right;
            
        }
    }
    
    return ans;

}

// Time Complexity -> O(N)
// Space Complexity -> O(N)
