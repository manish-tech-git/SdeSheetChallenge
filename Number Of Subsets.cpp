#include <bits/stdc++.h> 

// ********************************************** using recursion with memoization *************************************

// int f (int ind, int sum, vector <int> &num, vector <vector<int>> &dp)
// {
//     if (sum == 0) return 1;
//     if (ind == 0)
//         return num[0] == sum;
    
//     if(dp[ind][sum] != -1)
//         return dp[ind][sum];
    
//     int notTake = f(ind - 1, sum, num, dp);
    
//     int take = 0;
//     if( num[ind] <= sum )  take = f(ind - 1, sum - num[ind], num, dp);
        
//     return dp[ind][sum] = notTake + take;
// }

// *************************************** Using Tabulation ************************************************

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector <vector <int>> dp(n, vector <int> (tar +1, 0));
    
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    
    if(num[0] <= tar) dp[0][num[0]] = 1;
    
    for (int ind = 1; ind < n; ind++){
        
        for (int sum = 0; sum <= tar; sum++){
            
            int notTake = dp[ind - 1] [sum];
            int take = 0;
            if( num[ind] <= sum )  take = dp[ind - 1][sum - num[ind]];
            dp[ind][sum] = notTake + take;
             
        }
    }
    
    return dp[n-1][tar];
}


// Time Complexity ->  O(N * target)
// Space Complexity -> O(N * target)
