#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector <vector <int>> ans;
    
    if (intervals.size() == 0) return ans;
    sort (intervals.begin(), intervals.end());
    
    vector <int> tempInterval = intervals[0];   // Store first interval as a temporary interval for checking intervals with the other intervals
    
    for (auto it : intervals)
    {                                                                   //  temp      it
        if (it[0] <= tempInterval[1])                                   //  1         3     6       8       10
            tempInterval[1] = max(it[1], tempInterval[1]);              //  4         5     8       9       12
        
        else
        {
            ans.push_back(tempInterval);
            tempInterval = it;
        }
    }
    ans.push_back(tempInterval);
    return ans;
}


// Time Complexity - O(N*logN)
// Space Complexity - O(N)
