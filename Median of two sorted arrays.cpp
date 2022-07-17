double median(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    vector <int> ans;
    
    int i = 0; 
    int j = 0; 
    
    while (i < n && j < m){
        
        if (a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else {
            ans.push_back(b[j]);
            j++;
        }
     }
    
    while (i < n){
        ans.push_back(a[i]);
        i++;
    }
    while (j < m){
        ans.push_back(b[j]);
        j++;
    }
    
    double res;
    
    int size = ans.size();
    if (size % 2 == 1){
        res =  ans[size/2];
        
    }
    else{
        res = ((double)ans[size/2] + ans[size/2 - 1]) / 2.0;
    }
    return res;
}


// Time Complexity - O(N)
// Space Complexity - O(N)
