

int kthLargest(vector<int>& arr, int size, int K)
{
    
    priority_queue<int, vector <int>, greater <int> >pq;
    
    for(int i = 0 ; i < size; i++){
        pq.push(arr[i]);
        
        if(pq.size() > K)
            pq.pop();
    }
   return pq.top();
}

// Time Complexity - O(N * log k)
// Space Complexity - O(K)
