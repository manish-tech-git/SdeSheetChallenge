#include <bits/stdc++.h>
class Stack {
	
    queue <int> q;
    int size;
    
    public:
    Stack() {
       size = -1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return (q.empty());
    }

    void push(int element) {
        size++;
        q.push(element);
   
        for (int i = 0 ;i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(!q.empty())
        {
            int n = q.front();
            q.pop();
            size--;
            return n;
        }
        return -1;
    }

    int top() {
        if(!q.empty())
            return q.front();
        return -1;
    }
};


//Time Complexity: O(N)
//Space Complexity: O(N)
