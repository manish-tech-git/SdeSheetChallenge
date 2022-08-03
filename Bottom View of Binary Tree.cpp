// ********************************************** Bottom View of Binary Tree *********************************************
vector <int> bottomView(Node *root) 
    {
        
         vector <int> ans;
        if (root == NULL) return ans;
        
        map <int, int> topNode;
        
        queue <pair <Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while (!q.empty())
        {
            pair <Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            
           
            topNode[hd] = frontNode -> data;
            
            
            if (frontNode -> left)
                q.push(make_pair (frontNode -> left, hd - 1));
                
            if (frontNode -> right)
                q.push(make_pair(frontNode -> right, hd + 1));
            
            
        }
        
        
        for (auto it : topNode)
            ans.push_back (it.second);
            
        return ans;
        
}


// Time Complexity -> O(N.logN)
// Space Complexity -> O(N)
