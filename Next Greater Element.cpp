/*
1
4
9 3 6 5
    
ans ->  -1 6 -1 -1
    
*/


#include <bits/stdc++.h> 
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    stack <int> st;
    
    st.push(-1);
    vector <int> ans (n);
    
    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        // if the current element is greater then top element of stack then we will pop the element of stack untill we find the smaller one.
        while (!st.empty() && st.top() <= curr )
            st.pop();
        
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        
        st.push(curr);
        
    }
    return ans;
}

//Time Complexity: O(N)
//Space Complexity: O(N)
