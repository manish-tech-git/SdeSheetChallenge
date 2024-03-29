bool dfs (int node, vector<int>adj[], int vis[], int pathvis[], int check[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        //traverse for adjacent nodes
        for(auto it: adj[node]){
            if(vis[it] != 1){
                if(dfs(it, adj, vis, pathvis, check) == true){
                    check[node] = 0;
                    return true;
                }
                    
            }
            
            else if(pathvis[it]){
                check[node] = 0;
                return true;
            }
                
        }
        
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }

    
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathvis[V] = {0};
        int check[V] = {0};
        vector <int> safenodes;
        
        for (int i =0; i < V; i++){
            if(!vis[i]){
               dfs(i, adj, vis, pathvis, check);
            }
        }
        
        for (int i = 0; i < V; i++) {
            if(check[i] == 1)
            safenodes.push_back(i);
        }
        
        return safenodes;
    }
