// ******************************************************************* Using Tabulation ******************************************************************************
// House Robber
int solveTab (vector <int> &nums)
{ 
    int n = nums.size();

    vector <int> dp (n, 0);

    dp[0] = nums[0];
    
    int incl = 0;

    for (int  i  = 1; i < n; i++){
        
        int incl = dp[i-2] + nums[i];
        int excl = dp [i-1] + 0;
        dp[i] = max (incl, excl);

    }

    return dp[n-1];

}

// Time Complexity -> O(N)
// Space Complexity -> O(N)

//********************************************************** Using Memoization ************************************************************************

int solveRec (vector <int> nums, int n, vector <int> &dp)
{

    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int incl = solveRec (nums, n-2,dp) + nums[n];
    int excl = solveRec (nums, n - 1, dp) + 0;

    dp[n] = max (incl, excl);

    return dp[n];
}

// Time Complexity -> O(N)
// Space Complexity -> O(N) + Auxiliary Stack Space O(N)

//************************************************************ Using Space Optimization **************************************************************** 

int maximumNonAdjacentSum(vector<int> &nums){
   
//     int n = nums.size();
//     vector <int> dp (n+1, -1);
//     int ans = solveRec (nums, n-1, dp);
//     return ans;
//    return  solveTab(nums);
  
  
    
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    int curi;
    
    for (int i = 1; i < n; i++){
        int pick = nums[i];
            if(i > 1) pick += prev2;
        
        int notPick = 0 + prev;
        curi = max(pick, notPick);
        
        prev2 = prev;
        prev = curi;
    }
    
    return prev;
    
}

// Time Complexity -> O(N)
// Space Complexity -> O(1)


