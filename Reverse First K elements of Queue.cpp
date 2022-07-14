
#include <stack> 
queue<int> reverseElements(queue<int> q, int k)
{
    stack <int> s;
    
    for (int i = 0 ; i < k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);

    }
    
    int size = q.size() - k;
    
    while (size--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
        
    }
    
    return q;
}


// Time Complexity  -> O(N)
// Space Complexity -> O(N)
