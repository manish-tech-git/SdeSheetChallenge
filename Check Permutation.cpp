
#include <bits/stdc++.h>

bool areAnagram(string &str1, string &str2){
    
    if(str1.size() != str2.size()) return false;
    
    vector <int> s1(26, 0);
    vector <int> s2 (26, 0);
    
    for (int i = 0; i < str1.size(); i++)
    {
        s1[str1[i] - 'a']++;
        s2[str2[i] - 'a']++;
    }
    
    for (int i = 0; i < str1.size(); i++)
    {
        if( s1[i] != s2[i])
            return false;
    }
    return true;
    
}


// Time Complexity - O(N)
// Space Complexity - O (Alphabet Size - 26)
