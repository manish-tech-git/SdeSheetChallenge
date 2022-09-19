// *********************************** Using Memoization ***************************************************

#include<bits/stdc++.h>
int solve ( vector <int> &heights, int index, vector <int> &dp)
{
    if (index == 0)
        return 0;
    if (index < 0)
        return 1e9 + 7;
    
    if (dp[index] != -1)
        return dp[index];
    
    int left = solve (heights, index - 1, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if(index > 1)
      right = solve ( heights, index - 2, dp) + abs (heights[index] - heights[index - 2]);
   
    return dp[index] = min(left, right);
    
}

int frogJump(int n, vector<int> &heights)
{
    vector <int> dp(n, 0);
    dp[0] = 0;
    
    for (int i = 1; i < n; i++){
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if (i > 1)
        ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(fs, ss);
    }
   return dp[n-1];
}

// Time Complexity -> O(N)
// Space Complexity -> O(N) + Recursive Stack Space

// ************************************************ Using Tabulation ************************************************

int frogJump(int n, vector<int> &heights)
{
    vector <int> dp(n, 0);
    dp[0] = 0;
    
    for (int i = 1; i < n; i++){
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if (i > 1)
        ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(fs, ss);
    }
   return dp[n-1];
}

// Time Complexity -> O(N)
// Space Complexity -> O(N)




