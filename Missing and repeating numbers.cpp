#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    
    int dou;
    unordered_map <int, int> umap;
    for(auto i: arr){
        umap[i]++;
    }
    
    for (auto i : umap){
        if(i.second > 1)
            dou = i.first;
    }
    
    int all_sum = 0;
    for (int i = 0; i < arr.size(); i++)
        all_sum += arr[i];
    
    all_sum = all_sum - dou;
                               
    int sum = n * (n + 1) /2;    //Calculating Maximum Sum
    int missing = sum - all_sum; // finding missing value
    
    return {missing, dou};
}

//Time Complexity - O(N)
//Space COmplexity - O(N)
