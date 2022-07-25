//****************************************** using memoization *******************************************

int solve(int n, int arr[], int curr, int prev, vector <vector <int>> &dp)
    {
    // base case
      if ( curr == n) return 0;

      if (dp[curr][prev+1] != -1)
          return dp[curr][prev+1];

      int include = 0;
      //include 
      if (prev == -1 || arr[curr] > arr[prev])
       include = 1 + solve (n, arr, curr + 1, curr, dp);

      //exclude 
      int exclude = 0 + solve (n, arr, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(include, exclude);

    }

    
int longestSubsequence(int n, int a[])
{
   vector <vector <int> > dp (n, vector <int> (n+1, -1));
   return solve (n , a, 0, -1, dp);
}
