#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int ans = 0;
    sort(arr.begin(), arr.end());
    for (int i= 0; i < arr.size()-1; i++){
        if(arr[i] == arr[i+1])
            ans = arr[i];
            
    }
    
    return ans;
    
}
