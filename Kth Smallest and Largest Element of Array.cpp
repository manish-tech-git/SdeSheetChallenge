#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	
    sort(arr.begin(), arr.end());
    vector <int> v;
    int maxi = arr[k-1];
    int mini = arr[n-k];
    
    v.push_back(maxi);
    v.push_back(mini);
    
    return v;
}
