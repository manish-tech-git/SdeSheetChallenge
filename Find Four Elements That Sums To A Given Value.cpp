#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    //if(n < 4) return "No";
    
    sort (arr.begin(), arr.end());
    
    for (int i = 0; i < n; i++){                        //   Start iterating from starting index of array
        for (int j = n-1; j > i; j--){                  //   Start interating from ending index of array
          
            int p = target - arr[i] - arr[j];           
            int left = i + 1;
            int right = j - 1;
          
            while(left < right)                       
            {
                if(p == arr[left] + arr[right]) return "Yes";
                else if(arr[left] + arr[right] < p) left++;
                else right--;
            }
          
        }
    }
    
    return "No";
}

//Time Complexity - O(N^3)
