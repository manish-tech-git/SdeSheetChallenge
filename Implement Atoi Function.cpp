#include <bits/stdc++.h>

int atoi(string str) {
    int number = 0;
    int isNegative = 0;
    
    for (int i = 0; i < str.size(); i++){
        if(str[i] >= '0' and str[i] <= '9'){
            int digit = str[i] - '0';             //converting string into number
            number = number * 10 + digit;
        }
    }
    
    if(str[0] == '-')
        isNegative = 1;
    if(isNegative){
        number = number *(-1);
    }
    
    return number;
       
    
}

// Time COmplexity - O(N)
