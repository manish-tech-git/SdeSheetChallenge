
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int n, int m) {
	
    vector <int> ans;
    int i = 0;
    int j = 0;
    
    while (i < n &&  j < m) 
    {
        if (arr1[i] <arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < n )
    {
        ans.push_back(arr1[i]);
        i++;
    }
    
    while (j < m)
    {
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
        
}

// Time Complexity - O(N);
// Space Complexity - O(N)
