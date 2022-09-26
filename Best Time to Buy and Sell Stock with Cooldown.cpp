#include <bits/stdc++.h> 

// ********************************************** using recursion with memoization *************************************

int f(int ind, int buy, vector <int> &prices, int n, vector <vector<int>> &dp )
{
    if (ind >= n) return 0;
    
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if (buy){
       // int buykaro = -prices[ind] + f(ind + 1, 0, prices, n);
       // int skipkaro = 0 + f(ind+1, 1, prices, n);
         profit = max  (-prices[ind] + f(ind + 1, 0, prices, n, dp), 0 + f(ind+1, 1, prices, n, dp));
    }
    
    //int sellkaro = prices[ind] + f(ind + 1, 1, prices, n);
    //int sellskip = 0 + f(ind + 1, 0, prices, n);
    else{
    profit  =  max(prices[ind] + f(ind + 2, 1, prices, n, dp), 0 + f(ind + 1, 0, prices, n, dp));
    }
    
    dp[ind][buy] = profit;
    
}
 
// ************************************************* using Tabulation ************************************************

int SolveTab (vector <int> &prices)
{
    int n = prices.size();
    vector <vector <int>> dp (n+2, vector <int> (2, 0));
    
    for (int ind  = n -1; ind >= 0; ind--){
        for (int buy = 0; buy <=1; buy++){
            
            int profit = 0;
            if (buy){
               // int buykaro = -prices[ind] + f(ind + 1, 0, prices, n);
               // int skipkaro = 0 + f(ind+1, 1, prices, n);
                 profit = max  ( -prices[ind] + dp[ind + 1][0], dp[ind+1][1] );
            }

            //int sellkaro = prices[ind] + f(ind + 1, 1, prices, n);
            //int sellskip = 0 + f(ind + 1, 0, prices, n);
            else{
            profit  =  max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
       }
    }
    
    return dp[0][1];
}

// ************************************************************ using Space Optimization ****************************************
    
int SpaceOpt (vector <int> &prices)
{
   
    int n = prices.size();
    vector <int> front2(2, 0);
     vector <int> front1(2, 0);
     vector <int> curr(2, 0);
    
    for (int ind  = n -1; ind >= 0; ind--){
        for (int buy = 0; buy <=1; buy++){
            
            int profit = 0;
            if (buy){
               // int buykaro = -prices[ind] + f(ind + 1, 0, prices, n);
               // int skipkaro = 0 + f(ind+1, 1, prices, n);
                 profit = max  ( -prices[ind] + front1[0], front1[1] );
            }

            //int sellkaro = prices[ind] + f(ind + 1, 1, prices, n);
            //int sellskip = 0 + f(ind + 1, 0, prices, n);
            else{
            profit  =  max(prices[ind] + front2[1], front1[0]);
            }

            curr[buy] = profit;
       }
        front2 = front1;
        front1 = curr;
    }
    
    return curr[1];
    
}
   

// **************************** main function ****************************************************
    
int stockProfit(vector<int> &prices){
    //int n = prices.size();
    //vector <vector<int>> dp(n, vector <int> (2, -1));
    //return f(0, 1, prices, n, dp);
    //return SolveTab (prices);
    return SpaceOpt (prices);
}

