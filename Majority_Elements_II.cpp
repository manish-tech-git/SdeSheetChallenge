#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int n1 = n/3;
    
    vector <int> v;
    unordered_map <int, int > umap;
    
    for(int i = 0; i < arr.size(); i++){
        umap[arr[i]]++;
    }
    
    for(auto x : umap){
        if(x.second > n1){
            v.push_back(x.first);
        }
    }
    
    return v;

}
