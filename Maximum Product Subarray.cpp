int maximumProduct(vector<int> &arr, int n)
{
    
    int minProduct = 1;
    int maxProduct = 1;
    
    int res = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap (minProduct, maxProduct);
        }
        
        minProduct = min (minProduct * arr[i], arr[i]);
        maxProduct = max (maxProduct * arr[i], arr[i]);
        res = max (res, maxProduct);
    
    }
    
    return res;
	
}
