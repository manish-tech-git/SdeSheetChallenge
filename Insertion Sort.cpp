// Insertion Sort adapatable Algorithm

void insertionSort(int n, vector<int> &arr){
    int j;
    for(int i = 1; i<n; i++)
    {
        int temp = arr[i];
        for (j = i-1;j>=0;j--)
        {
            if(arr[j] > temp )
                arr[j+1] = arr[j];
            else
                break;
         }
        
        arr[j+1] = temp;
    }
}


// -> Adapdatable algorithm means it will not traverse to the whole array as it get smaller element from the current one it will break out.

// Time Complexity -> O(N^2)
// Space Complexity -> O(1)
