#include <bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix)
{
    vector<int> ans;
    
    for(int i = 0; i < matrix.size(); i++){
        
        for (int j = 0; j < matrix[0].size(); j++){
            
            ans.push_back(matrix[i][j]);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    return ans[ans.size()/2];
    
}
