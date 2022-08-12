#include<bits/stdc++.h>
void toposort (int node, vector<bool> &visited,
               stack <int> &s,  unordered_map <int, list <int> > &adj)
{
    
    visited[node] = 1;
    
    for (auto neighbour : adj[node]){
        if(!visited[neighbour])
            toposort (neighbour, visited, s, adj);
    }
    
    //push
    s.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    
    unordered_map <int, list <int> > adj;
    for (int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back (v);
    }
    
    // CAlls for dfS topological sort 
    vector <bool> visited(v);
    stack <int> s;
    
    for (int i =0; i<v; i++){
        if(!visited[i])
            toposort(i, visited, s, adj);
    }
    
    vector <int> ans;
    
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}


// Time Complexity -> O(V + E)
// Space Complexity -> O(N) or Linear
