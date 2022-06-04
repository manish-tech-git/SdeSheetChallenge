#include <queue>
#include <algorithm>

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    priority_queue <int> pq;
    
    for (int i = 0; i < kArrays.size(); i++){
        
        for (int j = 0; j < kArrays[i].size(); j++){
            
            pq.push(kArrays[i][j]);
            
        }
        
    }
    
    vector <int> v;
    
    while(!pq.empty()){
        int ans = pq.top();
        v.push_back(ans);
        pq.pop();
    }
    
    sort(v.begin(), v.end());
    
    return v;
    
}
