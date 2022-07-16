
#include<bits/stdc++.h>
int modularExponentiation(int xx, int n, int m) {
	
   long long int res = 1;
    long long x = xx;
    while (n > 0){
        
        if(n&1){
            res = (res * x % m) % m;
        }
        
        x = (x %m * x % m)%m;
        
        n = n >> 1;
        
    }
    return (int)res;
}

// Time Complexity - O(log b)
// Space Complexity - O(1)
