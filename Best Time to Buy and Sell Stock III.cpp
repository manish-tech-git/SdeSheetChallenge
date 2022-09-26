#include <bits/stdc++.h> 

// **************************************** using memoization ********************************************************
int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

    if(ind==n || cap==0) return 0;  //base case
    
    if(dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
        
    int profit;
    
    if(buy==0){  //We can buy the stock
        profit = max(0+getAns(Arr,n,ind+1,0,cap,dp), 
                    -Arr[ind] + getAns(Arr,n,ind+1,1,cap,dp));
    }
    
    if(buy==1){ //We can sell the stock
        profit = max(0+getAns(Arr,n,ind+1,1,cap,dp),
                    Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
    }
    
    return dp[ind][buy][cap] = profit;
}


// ************************************************************* using tabulation *****************************************
int solveTab (vector<int> &prices, int n)
{
          vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,0)));
    
        for (int ind = n-1; ind >= 0; ind--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                    
                    if (buy == 1){
                        dp[ind][buy][cap] = 
                            max(-prices[ind] + dp[ind + 1][0][cap], 
                               0 + dp[ind+1][1][cap]);
                    }
                    
                    else{
                        dp[ind][buy][cap] = 
                            max(prices[ind] + dp[ind+1][1][cap -1],
                               0 + dp[ind + 1][0][cap]);
                    }
                    
                }
            }
        }
    
    return dp[0][1][2];
    
    
}

// ************************************************************ using Space optimization *********************************
int spaceOpt (vector<int> &prices, int n)
{
    vector<vector<int>> after (2,vector<int>(3,0));
    vector<vector<int>> curr (2,vector<int>(3,0));
    
            for (int ind = n-1; ind >= 0; ind--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                    
                    if (buy == 1){
                        curr[buy][cap] = 
                            max(-prices[ind] + after[0][cap], 
                               0 + after[1][cap]);
                    }
                    
                    else{
                        curr[buy][cap] = 
                            max(prices[ind] + after[1][cap -1],
                               0 + after[0][cap]);
                    }
                }
             }
                
      after = curr;
       }
    
    return curr[1][2];
}


// ***************** Main Function ***************************

int maxProfit(vector<int>& prices, int n)
{
    //vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    
    //return getAns(prices,n,0,0,2,dp);
    //return solveTab (prices, n);
    return spaceOpt (prices, n);
}

