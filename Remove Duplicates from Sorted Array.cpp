#include<bits/stdc++.h> 

int removeDuplicates(vector<int> &arr, int n) {
	
    set<int> s;
    
    for (int i = 0; i < arr.size(); i++){
        s.insert(arr[i]);
    }
    
    return s.size();
    
}
