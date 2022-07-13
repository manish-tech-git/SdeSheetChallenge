// *********************************************** Using extra Space *************************************************

/*

         arr    ->     3   1   2   4   0   1   3   2
         
      LeftMax   ->    3    3   3   4   4   4   4   4
      
      RightMax  ->    4   4   4   4   3   3   3   2
      
      sum      ->     0   2   1   0   3   2   0   0
      
      
      
      Now find the minimum of the both leftMax and rightMax 
      
      ans = min (leftMax, rightMax)
      
      sum += ans - arr[i]
          


*/

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    
    vector <long> left ;
       long l = arr[0];
    
    vector <long> right;
    long r = arr[n-1];
    
    for (int i = 0; i < n; i++){
        l = max (l, arr[i]);
        left.push_back(l);
    }
    
    for (int  i = n-1; i >= 0; i--){
        r = max (r, arr[i]);
        right.push_back(r);
    }
    
    reverse (right.begin(), right.end());
    long sum = 0;
    for (int i = 0 ; i < n; i++){
        
        long ans = min (left[i], right[i]);
        long m = ans - arr[i];
        sum += m;
    }
     return sum;    
}

// Time Complexity - O(N)
// Space Complexity - O(N)

 

// ********************************* Without extra space *************************************************


#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    
    long sum = 0;
    
    
    long i = 0; 
    long j = n-1;
    long leftMax = 0;
    long rightMax = 0;
    
    while (i < j)
    {
      
        leftMax = max (leftMax, arr[i]);
         rightMax = max (rightMax, arr[j]);
        
        if (leftMax < rightMax){
            sum += leftMax - arr[i];
            i++;
           
        }
        else{
            sum += rightMax - arr[j];
            j--;
             
          }
        
        
    }
    return sum;    
}

// Time Complexity - O(N)
// Space Complexity - O(1)


