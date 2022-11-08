#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it: adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for(int i =0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        //find the topo Sort
        int vis[N] = {0};
        stack <int> st;
        for(int i =0; i< N; i++){
            if(!vis[i]){
                topoSort (i, adj, vis, st);
            }
        }
        
        //step2 do the distance things
        vector <int> dist(N);
        for (int i =0; i< N; i++) dist[i] = 1e9;
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for (auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
                
            }
        }
        for(int i =0; i< N;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends


// Time Complexity -> O (N + M)
// Space Complexity -> O(N)
