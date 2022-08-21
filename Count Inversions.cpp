#include <bits/stdc++.h>

void merge(long long *arr, int s, int e, long long &ans) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values from main array
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) 
    {
        first[i] = arr[mainArrayIndex++];
        
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) 
    {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays to main array   
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
            ans +=  len1 - index1;
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    //delete temporary arrays
    delete []first;
    delete []second;

}

void solve(long long *arr, int s, int e, long long &ans) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    solve(arr, s, mid, ans);
    
    //right part sort karna h 
    solve(arr, mid+1, e, ans);

    //merge
    merge(arr, s, e, ans);

}

long long getInversions(long long *arr, int n){
    
    long long ans = 0;
   
    solve (arr, 0, n-1, ans);
    
    return ans;
    
    
}

// Time Complexity -> O(NlogN)
// Space Complexity -> O(N)
