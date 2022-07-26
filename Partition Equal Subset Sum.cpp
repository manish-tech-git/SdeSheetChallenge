// **************************************** Using Memoization **********************************************************

bool solve (vector <int> arr, int n, int index, int target, vector <vector <int >> &dp)
{
    
    if (index >= n)
        return 0;
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;
    
    if (dp[index][target] != -1)
        return dp[index][target];
    
    bool include = solve (arr, n, index + 1, target - arr[index], dp);
    
    bool exclude = solve (arr, n, index +1, target, dp);
    
    return dp[index][target] = (include || exclude);
       
}

//************************************************ using Tabulation ****************************************************

bool solveTab (int n, vector<int> &arr, int total )
{
    vector  <vector <int > > dp (n+1, vector <int>( total +1, 0));
    
    for (int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    
    for (int index = n-1; index >= 0; index--){
        for (int target = 0; target <= total/2; target++){
            
            bool incl = 0; 
            if (target - arr[index] >= 0)
                incl = dp[index+1][target - arr[index]];
            
            bool excl = dp[index + 1][target];
            
            dp[index][target] = incl || excl;
            
        }
    }
    return dp[0][total/2];
}




bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
	for (int i = 0; i < n; i++)
        sum += arr[i];
    
    if (sum & 1)
        return 0;
    //int summ = sum/2;
    // vector <vector <int> > dp (n, vector <int> (summ + 1, -1));
    //return solve (arr, n, 0, sum/2, dp);
    
    return solveTab ( n, arr, sum);
}
