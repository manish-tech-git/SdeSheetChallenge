// ******************************************** using memoization ********************************************

int solve (int n, vector<int> &rack, int curr, int prev, vector<vector<int>> &dp )
{
     //base case
     if ( curr == n) return 0;
    
     if (dp[curr][prev+1] != -1)
         return dp[curr][prev+1];
    
     int include = 0;
     //include 
     if (prev == -1 || rack[curr] > rack[prev])
     include = rack[curr] + solve (n, rack, curr + 1, curr, dp);
    
     //exclude 
     int exclude = 0 + solve (n, rack, curr + 1, prev, dp);
     return dp[curr][prev + 1] = max(include, exclude);
    
}


int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    
    vector < vector <int> > dp(n , vector <int> (n+1, -1));
    return solve (n, rack, 0, -1, dp);
}
