int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int ans = arr[0];
    for(int i = 1; i < n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
