

#include <bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {

    sort (at, at + n);
    sort (dt, dt + n);
    int i = 0; 
    int j = 0;
    
    int maxTrain = 0;
    int maxPlatform = 0;
    
    while (i < n && j < n)
    {
        if (at[i] <= dt[j]){
            maxTrain++;
            i++;
        }
        else{
            maxTrain--;
            j++;
        }
        
        maxPlatform = max(maxPlatform, maxTrain);
    }
return maxPlatform;  
}


// Time Complexity - O(NlogN)
// Space Complexity - O(1)
