#include <bits/stdc++.h>
void solve (vector <int> arr, vector <int> output, int index, vector <vector <int>> &ans)
    
{
    if (index >= arr.size()){
        ans.push_back(output);
        return;
    }
    
    //exclude Call
    solve (arr , output, index + 1, ans);
    
    //include Call
    int ele = arr[index];
    output.push_back (ele);
    solve (arr, output , index + 1, ans);
    
    
}

vector<int> subsetSum(vector<int> &arr)
{
    vector <vector <int>> ans;
    vector <int> output;
    int index = 0; 
    
    vector <int>res;
    
    solve (arr, output, index, ans);
    
    for (int i = 0; i < ans.size(); i++ ){
        int sum = 0;
        for (int j = 0; j < ans[i].size(); j++){
           sum += ans[i][j];
        }
        res.push_back(sum);
    }
    
    sort (res.begin(), res.end());
    return res;
       
}
