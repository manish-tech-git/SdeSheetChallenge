#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    
    
   unordered_set <string> st;
    
    int n = word.size();
    
    
    for (int i = 0; i < n; i++){
        string str = "";
        for (int j = i; j < n; j++){
            str +=word[j];     
            st.insert(str);
        }
        
    }
    
    return st.size();
 }
