

int minSumPath(vector<vector<int>> &grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    
    vector <vector <int> > ans (n , vector <int> (m, 0));
    
    for (int i = n-1; i >= 0; i--){
        for (int j = m-1; j >= 0; j--){
            
            if (i == n-1 && j == m-1)
                ans[i][j] = grid[i][j];
            
            else if (i == n-1)
                ans[i][j] = ans[i][j+1] + grid[i][j];
            
            else if (j == m-1)
                ans[i][j] = ans[i+1][j] + grid[i][j];
            
            else
                ans[i][j] = min(ans[i][j+1], ans[i+1][j]) + grid[i][j];
        }
    }
    return ans[0][0];
}

