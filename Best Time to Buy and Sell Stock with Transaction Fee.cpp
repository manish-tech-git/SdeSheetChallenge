#include <bits/stdc++.h> 

// ********************************************* Using recursion with memoization *************************************

int f (int ind, int buy, vector <int> &prices, int fee, vector <vector<int>> &dp )
{
     if (ind == prices.size()) return 0;
    
     if (dp[ind][buy] != -1)
         return dp[ind][buy];
    
    int profit = 0;
    
    if(buy){
        profit = max(( -prices[ind]  + f(ind+1, 0, prices, fee, dp)),
                   
                (0 + f (ind +1, 1, prices, fee, dp)));
        
    }
    else{
    profit =  max (( (prices[ind] - fee)  + f (ind + 1, 1, prices, fee, dp)), 
                  ( f(ind + 1, 0, prices, fee, dp) ));
    }
    
    return dp[ind][buy] = profit;
    
}


// ******************************************** using tabulation *********************************************************
int solveTab (vector <int> &prices, int fee)
{
    int n = prices.size();
    vector <vector<int>> dp (n+1, vector <int> (2, 0));
    for (int ind = n-1; ind >= 0; ind --){
        for (int buy = 0; buy <= 1; buy++){
            
            if(buy){
                dp[ind][buy] = max((-prices[ind]  + dp[ind+1][0]) , dp[ind +1][1]);

            }
            else{
            dp[ind][buy] = max (  (prices[ind] - fee)+dp[ind + 1][1],  dp[ind + 1][0]);
            }
        }
    }
    
    return dp[0][1];
}


// ********************************************** using Space Optimization ***********************************************

int spaceOpt (vector <int> &prices, int fee)
{
    int n = prices.size();
    vector <int> curr(2, 0);
    vector <int> next (2, 0);
    for (int ind = n-1; ind >= 0; ind --){
        for (int buy = 0; buy <= 1; buy++){
            
            if(buy){
                curr[buy] = max((-prices[ind]  + next[0]) , next[1]);

            }
            else{
            curr[buy] = max (  (prices[ind] - fee)+ next[1],  next[0]);
            }
        }
        next = curr;
    }
    
    return curr[1];  
    
}

// ***************************************** Main Function *************************************************************
int maximumProfit(int n, int fee, vector<int> &prices) {
    
    //vector <vector<int>> dp (n, vector <int> (2, -1));
    //return f(0, 1, prices, fee, dp);
    //return solveTab (prices, fee);
    return spaceOpt(prices, fee);
}
