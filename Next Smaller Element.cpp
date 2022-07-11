

#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
      stack <int> st;
      vector <int> ans(n,-1);
    
for(int i = n-1; i >= 0; i--)
    {
       while (!st.empty() && st.top() >= arr[i]){
           st.pop();
       }
    if (i < n && !st.empty()){
        ans[i] = st.top();
    }
    st.push(arr[i]);
    
}
     return ans;
}

// Time Complexity -> O(N)
// Space Complexity -> O(N)
