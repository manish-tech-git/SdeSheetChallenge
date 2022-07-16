#include<bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector <pair <int, int> > acti;
    
    for (int i = 0; i< n ;i++){
        acti.push_back({finish[i], start[i]});
    }
    
    sort (acti.begin(), acti.end());
    int count   = 1;
    int time_limit = acti[0].first;
    
    for (int i = 1; i < n; i++){
        if (acti[i].second >= time_limit){
            count++;
            time_limit = acti[i].first;
        }
    }
    return count; 
}


// Time Complexity  - O(N)
// Space Complexity - O(N)
