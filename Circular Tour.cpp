
int firstCircularTour(vector<int>& petrol, vector<int>& distance, int n)
{
	
    long long int deficit = 0;
    long long int balance = 0;
    long long int start = 0;
    
    for (int i = 0; i < n; i++ )
    {
        balance += petrol[i] - distance[i];
        if (balance < 0){
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    
    if (deficit + balance >= 0){
        return start;
    }
    return -1;
}


// Time Complexity - O(N)
// SpaceComplexity - O(1)
