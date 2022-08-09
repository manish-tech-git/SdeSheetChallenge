#include<bits/stdc++.h>

string expand (int start, int end, string s){
    while (start >= 0 && end < s.size()){
        if (s[start] != s[end]){
            break;
        }
        start--;
        end++;
    }
    
    return s.substr (start + 1, end - start - 1);
}

string longestPalinSubstring(string str)
{
    string longest;
    
    int n = str.size();
    for (int i = 0; i< n; i++){
        string odd = expand(i, i, str);
        if (odd.size() > longest.size()){
            longest = odd;
        }
    }
    
    for (int i = 0; i< n;i++){
        string even = expand (i, i+1, str);
        if (even.size() > longest.size()){
            longest = even;
        }
    }
    
    return longest;
    
}


// Time Complexity -> O(N^2)
// Space Complexity -> O(N)
