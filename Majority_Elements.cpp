#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int major = n/2;
    
    unordered_map <int, int> umap;
    
    for(int i = 0; i < n; i++){
        if(++umap[arr[i]] > major)
            return arr[i];
    }
    return -1;
    
}
