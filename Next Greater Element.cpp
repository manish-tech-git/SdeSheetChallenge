/*
1
4
9 3 6 5
    
ans ->  -1 6 -1 -1
    
*/


#include <bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    
    stack <int> s;
    vector <int> v(n, -1); // Declaring vector with values -1
 
    
    for (int i = arr.size() -1; i >= 0; i--){
    
        // if the current element is greater then top element of stack then we will pop the element of stack untill we find the smaller one.
        while(!s.empty() && arr[i] >= s.top()){
            s.pop();
        }

        if( i < n && !s.empty()) {
            v[i] = s.top();
        }
    
        s.push(arr[i]);
    
    }

    return v;

}

//Time Complexity: O(N)
//Space Complexity: O(N)
