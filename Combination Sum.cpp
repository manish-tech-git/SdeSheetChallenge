#include<bits/stdc++.h>

void solve (vector <int> &candidates, vector <vector <int> > &ans, vector <int> &temp, int target, int currIndex, int currSum)
{
    
     if (currSum == target){
            ans.push_back (temp);
            return;
        }
    
        if (currIndex >= candidates.size()) return;
    
        if (currSum > target) return;
    
        
       
        
       //take the element
        temp.push_back (candidates[currIndex]);
        solve (candidates, ans, temp, target, currIndex, currSum + candidates[currIndex]);
        temp.pop_back();
    
       //skip the element
       solve(candidates, ans, temp, target, currIndex + 1, currSum);
   
}




vector<vector<int>> combSum(vector<int>& candidates, int target)
{
        vector <vector <int> > ans;
        vector <int> temp;
        sort (candidates.begin(), candidates.end());
        solve(candidates, ans, temp, target, 0, 0);
        return ans;
}


