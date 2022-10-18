
int kthElement(int A[], int B[], int m, int n, int k_req)
    {
      int i =0,j= 0;  
      int k = 0;// keep incrementing k
    while(i < m && j < n)
    {
        if(A[i] < B[j])
        {
            k++;
            if(k == k_req)
                return A[i];
            i++;
        }
        else
        {
            k++;
            if(k == k_req)
                return B[j];
            j++;
        }
    }
 
    // If array B[] is completely traversed
    while(i < m)
    {
        k++;
        if(k == k_req)
            return A[i];
        i++;
    }
 
    // If array A[] is completely traversed
    while(j < n)
    {
        k++;
        if(k == k_req)
            return B[j];
        j++;
    }
        
  }


// Time Complexity -> O(N)
// Space Complexity -> O(1)
