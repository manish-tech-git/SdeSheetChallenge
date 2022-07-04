#include<bits/stdc++.h>

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
   int n = start.size();
   pair <int, int> a[n + 1];
    int i;
    for (int i = 0 ; i < n ; i++)
    {
        a[i].first = end[i];  // Storing the Finish time 
        a[i].second = i;      // Storing the corresponding index
    }
    //Sort the Pair according to their finish time
    sort(a, a + n);
    int time_limit = a[0].first; // store the finish time of first meeting
    
    vector <int> m;
    m.push_back(a[0].second + 1); // push the first meeting index value
    
    for (int i = 1; i < n; i++)
    {
        if(start[a[i].second] > time_limit)   // comparing the time limit 
        {
            m.push_back(a[i].second + 1);
            time_limit = a[i].first;
        }
    }
    
    return m;
    
    
}

// Time Complexity - O(N logN)
