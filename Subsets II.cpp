// ************************************************* Unique Subsets **************************************************

#include <bits/stdc++.h>

void solve (vector<int> arr, int index, vector <int> output, set<vector <int> > &ans)
{
     if (index >= arr.size()){
         sort(output.begin(), output.end());
         ans.insert(output);
         return;
     }   
    
    // Exclude
    solve (arr, index + 1, output, ans);
    
    //include
    int ele = arr[index];
    output.push_back (ele);
    solve (arr, index + 1, output, ans);
    //output.pop_back();
    
  
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
   vector <vector <int>> result;
    set <vector<int>> ans;
    vector <int> output;
    
    int index = 0;
    
    solve (arr, index, output, ans);
    
    for (auto it : ans){
        result.push_back(it);
    }
    
    
    return result;
}

