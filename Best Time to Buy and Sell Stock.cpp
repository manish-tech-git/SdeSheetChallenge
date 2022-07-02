// Intution  behind this question 
// always pick out the smallest element and calculate the profit and with each array index values but store the maximise profit in a sepearate variable


#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int mini = INT_MAX;
    int max_Profit = INT_MIN;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int left = prices[i];
        mini = min(mini, left);
        profit = prices[i] - mini;
        max_Profit = max( profit, max_Profit);
        
    }
    return max_Profit;
    
}

