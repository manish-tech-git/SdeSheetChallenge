//With using set (or using extra space)

#include<bits/stdc++.h> 

int removeDuplicates(vector<int> &arr, int n) {
	
    set<int> s;
    
    for (int i = 0; i < arr.size(); i++){
        s.insert(arr[i]);
    }
    
    return s.size();
    
}

// Time COmplexity - O(N)
// Space Complexity - O(N)


//******************************* Without using extra Space ***********************************************

#include<bits/stdc++.h> 

int removeDuplicates(vector<int> &arr, int n) {
	
  int  i = 0;
  int j = 1;
    int size = n;
    
    while (i < n-1 && j < n)
    {
        if (arr[i] == arr[j]){
            size -= 1; 
        }
        i++;
        j++;
    }
    return size;
    
}

// Time COmplexity - O(N)
// Space Complexity - O(1)

