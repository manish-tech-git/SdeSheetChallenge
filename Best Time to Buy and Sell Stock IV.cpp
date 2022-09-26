#include <bits/stdc++.h> 

int spaceOpt (vector<int> &prices, int n, int k)
{
    vector<vector<int>> after (2,vector<int>(k+1,0));
    vector<vector<int>> curr (2,vector<int>(k+1,0));
    
            for (int ind = n-1; ind >= 0; ind--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= k; cap++){
                    
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
    
    return curr[1][k];
    
}



int maximumProfit(vector<int> &prices, int n, int k)
{
    
    return spaceOpt(prices, n, k);
    
}
