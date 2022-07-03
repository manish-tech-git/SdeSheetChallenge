#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
   int n = arr.size();
   int count = 0;
    for (int i = 0; i < n; i++ ){
        int ans = 0;
        for (int j = i; j < n; j++){
            ans = ans ^ arr[j];
            if(ans == x)
                count++;
            
            }
    }
    
    return count;
}


//Time Complexity - O(N^2)
