

class Solution
{
    public:
  
    vector<int> topView(Node *root)
    {
        vector <int> ans;
        if (root == NULL) return ans;
        
      
       // For storing horizontal distance and root -> data
        map <int, int> topNode;
        
      
       // Make a queue of pair Node and horizontal distance
        queue <pair <Node*, int> > q;
        
        // push first root of tree
        q.push(make_pair(root, 0));
        
        while (!q.empty())
        {
            pair <Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            
          
          // for checking that given data already present or not corresponding to horizontal distance
            if (topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode -> data;
            
            
            // push left node of tree if present and decreament horizontal distance
            if (frontNode -> left)
                q.push(make_pair (frontNode -> left, hd - 1));
                
          
          
            // push right node of tree if present and increament horizontal distance
            if (frontNode -> right)
                q.push(make_pair(frontNode -> right, hd + 1));
            
      }
        
        
        for (auto it : topNode)
            ans.push_back (it.second);
            
        return ans;
        
    }

};


