// ************************************************************ Using Memoization ************************************************************************

int solveMem (vector<int> &values, vector<int> &weights, int index, int capacity, vector <vector <int>>& dp  )
{
    
    if (index <= 0)
        if (weights[0] <= capacity)
            return values[0];
        else
            return 0;
    
        if(dp[index][capacity] != -1)
            return dp[index][capacity];
    
    // include call
    int include = 0;
    if (weights[index] <= capacity)
    include =    values[index] + solveMem (values, weights, index-1, capacity - weights[index], dp);
    
    // exclude 
    int exclude = 0 +  solveMem (values, weights, index-1, capacity , dp);
    
    int ans = max (exclude, include);
    dp[index][capacity] = ans;
    return dp[index][capacity];
      
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector <vector <int>> dp(n, vector <int> (w+1, -1));
    return solveMem ( values, weights, n-1, w, dp);
}
