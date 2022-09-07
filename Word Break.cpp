#include <bits/stdc++.h>

bool solve (int index , string s, set <string> &st, vector <int> &dp)
{
    if ( index == s.size()) return true;
    
    string temp;
    
    if (dp[index] != -1) return dp[index];

    for (int j = index; j<s.size(); j++){
       temp += s[j];
        if (st.find(temp) != st.end())
        {
            if (solve (j+1, s, st, dp)) return dp[index] = 1;
        }
    }
    return  dp[index] = 0;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    set <string> st;
    for (auto it : arr) st.insert(it);
    int size = target.size();
    vector <int> dp(size, -1 );
    return solve (0, target, st, dp);
}
