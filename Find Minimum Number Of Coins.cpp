
int findMinimumCoins(int amount) 
{

      int  arr [9] =  {1000, 500, 100, 50, 20, 10, 5, 2, 1};
      int count  = 0;
      int rupee = amount;
       
    for (int i = 0 ; i < 9; i++){
        int ans = rupee / arr[i];
        count += ans;
        if (ans >= 1){
            int rem = rupee % arr[i];
            rupee = rem;
        }
        
    }
    return count;

}

// Time Complexity - O(N)
// SpaceComplexity - O(1)
