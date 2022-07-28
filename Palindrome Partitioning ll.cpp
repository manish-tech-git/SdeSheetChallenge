
// ************************************************** using Memoization *********************************************************

#include <bits/stdc++.h>
bool isPalindrome (int i , int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])  return false;
            i++;
            j--;
           
    }
    return true;
}

int solve (int i, int n, string &str, vector <int> &dp)
{
    if ( i == n)
          return 0;
    if (dp[i] != -1)
        return dp[i];
    
    int mini = INT_MAX;
    
    for (int j = i; j < n; j++){
        if(isPalindrome(i, j, str)){
            int cost = 1 + solve (j+1, n, str, dp );
            mini = min (mini, cost);
    }
}
    
    return dp[i] = mini;
}


int palindromePartitioning(string str) {
    
    vector <int> dp (str.size(), -1);
    return solve (0, str.size(), str, dp) - 1;
 
}



// ************************************* using Tabulation ********************************************************

#include <bits/stdc++.h>
bool isPalindrome (int i , int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])  return false;
            i++;
            j--;
           
    }
    return true;
}

int palindromePartitioning(string str) {
    
     int n = str.size();
     vector <int> dp  (n+1, 0);
    
    for (int i = n- 1; i >= 0; i--)
    {
         int mini = INT_MAX;
    
        for (int j = i; j < n; j++){
            if(isPalindrome(i, j, str)){
                int cost = 1 + dp[j+1];
                mini = min (mini, cost);
        
            }
    }
    dp[i] = mini;
 
    }
    return dp[0] -1;
}

