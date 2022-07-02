#include <bits/stdc++.h>


// Using Vector 
vector<int> findMedian(vector<int> &arr, int n){
	
    vector <int> ans;
    vector <int> temp;
    
    for (int i = 0 ; i < n; i++){
        temp.push_back(arr[i]);
        if(temp.size() % 2 != 0){
            
            sort(temp.begin(), temp.end());
            int ll = temp[temp.size()/2];
            ans.push_back(ll);
        }
        
        else{
            
            sort(temp.begin(), temp.end());
            int n = temp.size();
            int sum = temp[n/2] + temp[(n-1)/2];
            ans.push_back(sum/2);
            
        }
    }
    return ans;
	
}

// Using Priority Queue - Optimised Approach

#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int> maxheap;
    priority_queue<int, vector<int> , greater<int>> minheap;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
 
        if(i%2==0)
        {
            minheap.push(arr[i]);
            maxheap.push(minheap.top());
            minheap.pop();
            vec.push_back(maxheap.top());
        }
        else
        {
            maxheap.push(arr[i]);
            minheap.push(maxheap.top());
            maxheap.pop();
            int num = (maxheap.top() + minheap.top())/2;
            vec.push_back(num);
        }
    }
    return vec;
}

