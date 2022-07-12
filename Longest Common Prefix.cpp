#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    string str = "";
    //Sort the strings
    sort(arr.begin(), arr.end());
    
    //Find the length of smallest string
    int len = arr[0].size();
    
    //Run loop for the smallest string length
    for (int i = 0 ;  i < len; i++)
    {
        //Comparing first and last strings
        if(arr[0][i] == arr[n -1][i])
            str += arr[0][i];
        
        //Else stop comparing if any character seem different first time
        else 
            break;
    }
    return str;
    
}


// Time Complexity - O(NlogN)
// Space Complexity - O(1)
