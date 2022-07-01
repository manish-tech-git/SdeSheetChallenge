

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
