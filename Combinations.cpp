#include <bits/stdc++.h> 

void solve (vector <vector<int> > &ans, vector <int> &temp, int st, int num, int n, int k)
{
    if (num == k){
        ans.push_back(temp);
        return;
    }
    
    for (int i = st; i < n; i++){
        temp.push_back(i+1);
        solve (ans, temp, i+1, num + 1, n, k);
        temp.pop_back();
    }
    
}

vector<vector<int>> combinations(int n, int k)
{
    vector<vector<int>> ans;
    if (n < k) return ans;
    vector <int> temp (0, k);
    solve (ans, temp, 0, 0, n, k);
    return ans;
}


