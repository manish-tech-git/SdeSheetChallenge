#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    
    
    long long sum = 0;
    long long cur_sum = 0;
    
    for(int i = 0; i < n; i++){
        
        cur_sum = cur_sum + arr[i];
        if(cur_sum > sum ){
            sum = cur_sum;
        }
        
        if(cur_sum < 0)
            cur_sum  = 0;
    }
    
    return sum;
}
