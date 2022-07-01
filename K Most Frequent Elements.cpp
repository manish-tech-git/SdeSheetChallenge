

#include<bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map <int, int > umap;
    
    for (auto i : arr)
        umap[i]++;
    
    priority_queue <pair<int, int>> q;
    for (auto i : umap)
    {
        q.push({i.second, i.first});
    }
    
    vector <int> v;
    for (int i = 0; i < k; i++){
        v.push_back(q.top().second);
        q.pop();
    }
    sort(v.begin(), v.end());
    return v;
   
}

/*

Time Complexity: O(k log d + d), where d is the count of distinct elements in the array. 
        To remove the top of priority queue O(log d) time is required, so if k elements are removed then O(k log d) time is required 
        and to traverse the distinct elements O(d) time is required.

Auxiliary Space: O(d), where d is the count of distinct elements in the array. 
    To store the elements in HashMap O(d) space complexity is needed.

*/
