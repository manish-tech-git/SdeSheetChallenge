#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  int sum = 0;
    
    int maxi = 0;
    
    int n = arr.size();
    
    unordered_map<int, int> umap;
    
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0){
            maxi = i+ 1;
        }
        else
        {
            if(umap.find(sum)!= umap.end())
                maxi = max(maxi, i - umap[sum]);
            else
                umap[sum] = i;
        }
    }
    return maxi;

}
