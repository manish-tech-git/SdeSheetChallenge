#include <bits/stdc++.h> 
int mod = (int) (1e9 + 7);

// ********************************************** Using recursion with memoization ****************************************

int f (int ind, int sum, vector <int> &num, vector<vector<int>> &dp)
{
    if(ind < 0){
        if(sum == 0) return 1;
        else return 0;
    }
    
    if(dp[ind][sum] != -1) return dp[ind][sum];
    
    int notTake = f(ind - 1, sum, num, dp);
    int take = 0;
    if( num[ind] <= sum )  take = f(ind - 1, sum - num[ind], num, dp);
        
    return dp[ind][sum] = (notTake + take) % mod;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector <vector <int>> dp(n, vector <int> (tar +1, -1));
    
    return f(n-1, tar, num, dp);
    
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for (auto &i: arr) totalSum += i;
    
    if ((totalSum - d < 0 ) || (totalSum - d) % 2 ) return false;
    
    return findWays(arr, (totalSum - d) / 2);
    
}

// Time Complexity -> O(N * target)
// Space Complexity -> O(N * target) + Auxiliary Space

