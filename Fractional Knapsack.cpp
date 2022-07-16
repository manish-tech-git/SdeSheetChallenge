#include<bits/stdc++.h>
// Compare each pair of items -> value / weight values
bool comp(pair <int, int> &item1, pair <int, int> &item2){
    
    double r1 = (double)item1.second / (double) item1.first;
    double r2 = (double)item2.second / (double) item2.first;
    
    return r1 > r2;
    
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // sort the pair according to value / weight
    sort (items.begin(), items.end(), comp);
    
    int curr_weight = 0; 
    
    double profit = 0.0;
    
    for (int i = 0; i < n; i++){
        if(curr_weight + items[i].first <= w){    // check whether that we can take whole weight at once or not
            curr_weight += items[i].first;
            profit += items[i].second; // Add the profit
        }
        
        else{
            //if we don't have much weight to consume whole then we take their fraction
            int remained_Weight = w - curr_weight;      
            profit += ((double)items[i].second/(double)items[i].first) * (double)(remained_Weight);
            break;    //break the loop because it would be the last option to choose weight;
        }
    }
    return profit;    
}

// Time Complexity - O(Nlogn)
// Space Complexity - O(1)
