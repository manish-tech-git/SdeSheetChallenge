#include<bits/stdc++.h>


// ***************************** Using Recursion *********************************
/*
 
int recursive(int i, int j, vector<vector<int>> &triangle, int n )
{
    if (i == n-1) 
        return triangle[n-1][j];
    
    int d  =  triangle[i][j] +  recursive(i+1, j, triangle, n);
    int dg =  triangle[i][j] +  recursive(i+1, j+1, triangle, n);
    
    return min (d, dg);
}
*/

// ******************************************* Using Tabulation ******************************



int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector <vector<int>> dp (n, vector <int> (n, 0));
    for (int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];
    
    for (int i = n-2;  i >= 0; i--){
        
        for (int j = i; j >= 0; j--){
            
            int d = triangle[i][j] + dp[i+1][j+1];
            int dg = triangle[i][j] + dp[i+1][j];
            dp[i][j] = min (d, dg);
        }
    }
    return dp[0][0];
}


// Time Complexity -> O(NM)
// Space Complexity -> O(NM)




