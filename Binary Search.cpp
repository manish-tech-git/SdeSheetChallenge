// **************************************** Using Recursion *********************************************

int search (int *arr, int st, int end, int val)
{
    if (st > end) return -1;
    
    int mid = (st + end ) / 2;
    
    if (arr[mid] == val) return mid;
    
    if (arr[mid] < val){
        search (arr, mid + 1, end, val);
    }
    else{
        search (arr, st, mid-1, val);
    }
    
}

int binarySearch(int *input, int n, int val)
{
    int start = 0;
    
    int ans = search (input, 0, n, val);
    
    return ans;
    
}


// Time Complexity  - O(log N)


