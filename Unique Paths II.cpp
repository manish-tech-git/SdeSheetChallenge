int mod = (int) (1e9 + 7);

// ******************************* recursion *******************************************************
// int f(int i, int j,vector< vector< int> > &mat, vector <vector <int>> &dp )
// {
//     if (i == 0 && j == 0) return 1;
//     if (i < 0 ||  j < 0) return 0;
    
//     if (i >= 0 && j >= 0 && mat[i][j] == -1) return 0;
    
//     if (dp[i][j] != -1)
//         return dp[i][j];
    
//     int up =  f(i-1, j, mat, dp);
//     int left = f(i, j-1, mat, dp);
    
//     return dp[i][j] =   up + left;
    
// }


// ********************************************** Using Tabulation ***********************************

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
     int dp[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] == -1) dp[i][j] = 0;
            else if (i == 0 && j == 0 ) dp[i][j] = 1;
            else{
                int up = 0, left = 0;
               if (i > 0)  up = dp[i-1][j];
               if (j > 0)  left = dp[i][j-1];
                dp[i][j] = (up + left) % mod;
                
            }
        }
    }
    
    return dp[n-1][m-1];
    
}

// Time Cmplexity -> O(N)
// Space Complexity -> O(N)
