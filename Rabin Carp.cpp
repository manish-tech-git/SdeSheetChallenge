vector<int> stringMatch(string &str, string &pat) {
    vector <int> ans;
    
       int n = str.size();
    int m = pat.size();
    
    for (int i = 0; i< n -m + 1; i++)
    {
        string st = str.substr(i, m);
        if (st == pat)
           ans.push_back(i);
        
    }
    return ans;
}
