// Brute force Approach 

#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
      sort(arr.begin(), arr.end());
      int maxi = 1;
      int i = 0, j = 1;
      int counter = 1;
    
     for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1]-1)
        {
            counter++;
        }
        else if(arr[i]==arr[i+1])
        {
            continue;
        }
        else if(arr[i]!=arr[i+1]-1)
        {
              // maxi = max(maxi, counter);
            counter=1;
        }
       maxi = max(maxi , counter);  
    }
    
    return maxi;
}

//Time Complexity - O(N log N) (for sorting the array) + O(N) (for traversing the elements) => O(N log N)


// Optimised Approach
