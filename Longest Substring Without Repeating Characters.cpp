#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    
    int maxi = INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
         unordered_map <int, int> umap;
            int counter = 0;
            for (int j = i; j < input.size(); j++){
                umap[input[j]]++;
                if(umap[input[j]] > 1)
                {
                    maxi = max(maxi , counter);
                        break;
                }
                counter++;
            }
        maxi = max(maxi, counter);
    } 
    return maxi;
    
}


//Time Complexity - O(N^2)
