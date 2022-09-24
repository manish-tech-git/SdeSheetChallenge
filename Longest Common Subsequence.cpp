#include <bits/stdc++.h> 

// ******************* using recursion ***************************************************************
int recursion (string &s, string &t, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return 0;
    
    if (s[ind1] == t[ind2]) return 1 + recursion(s, t, ind1 - 1, ind2 - 1);
    else
        return max(recursion(s, t, ind1-1, ind2), recursion(s,t,ind1, ind2 -1));
    
}


// ******************************** using memoization *************************************************

int memo(string &s, string &t, int ind1, int ind2, vector<vector <int>> &dp)
{
    if(ind1 < 0 || ind2 < 0) return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    
    if (s[ind1] == t[ind2]) 
       return dp[ind1][ind2] = 1 + memo(s, t, ind1 - 1, ind2 - 1, dp);
    else
       return dp[ind1][ind2] =  max(memo(s, t, ind1-1, ind2, dp), memo(s,t,ind1, ind2 -1, dp));
    
}

// ******************************* Using Tabulation ****************************************************

int solveTab (string & s, string & t)
{
        int n = s.size();
        int m = t.size();
    
    vector <vector<int>> dp (n+1, vector <int>(m+1,-1));
    
    for(int j=0; j<=m; j++) dp[0][j]=0;
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
  
}

// ************************************************* using space Optimization ******************************

int spaceOpt(string & s, string & t)
{
        int n = s.size();
        int m = t.size();
    
    vector <int> prev(m+1, 0), curr(m + 1, 0);
    
    for(int j=0; j<=m; j++) prev[j]=0;
    //for(int i=0; i<=n; i++) curr[0]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
               curr[j]=1+prev[j-1];
            else
                curr[j]=max(prev[j], curr[j-1]);
        }
        
        prev = curr;
        
    }
    return prev[m];
  
}

//main function..........................

int getLengthOfLCS(string & str1, string & str2) {
    int n = str1.size();
    int m = str2.size();
    //vector <vector<int>> dp (n, vector <int>(m,-1));
    //return recursion(str1, str2, n-1, m-1);
    //return memo(str1, str2, n-1, m-1, dp);
    //return solveTab(str1, str2);
    return spaceOpt (str1, str2);
}
