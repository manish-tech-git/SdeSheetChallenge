#include<bits/stdc++.h>

class Kthlargest {
public:
    priority_queue< int , vector <int> , greater <int> > pq;
    int size;
    Kthlargest(int k, vector<int> &arr) {
       size = k;
        for(int i = 0; i < arr.size(); i++){
            pq.push(arr[i]);
            if(pq.size() > size)
                pq.pop();
        }
        
        
        
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
        if(pq.size() > size)
            pq.pop();
    }

    int getKthLargest() {
       // Write your code here.
        return pq.top();
    }

};

// Time Complexity - O(Nlogk)
// Auxiliary Space: O(n)
