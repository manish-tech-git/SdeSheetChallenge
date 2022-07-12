#include<bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>>& q) {
    
    priority_queue <int, vector <int>,  greater <int> > pq;
    
    vector <int > ans;
    
   
        for (int i =0; i < q.size(); i++)
        {
                //Initialise new vector...
                vector <int> vect = q[i];

                // Checking that given operation is a pop operation or push operation...
                if(vect.size() == 2) pq.push(vect[1]);
                if (vect.size() == 1)
                {
                    if(!pq.empty()){
                      ans.push_back(pq.top());
                         pq.pop();
                    }
                }
         }
    return ans;
}
