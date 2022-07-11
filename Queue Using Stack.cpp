#include<bits/stdc++.h>
using namespace std;
class Queue {
    
    stack<int>st1;
    stack<int>st2;
    public:
    Queue() {
           }

    void enQueue(int val) {
       
        st1.push(val);
    }

    int deQueue() {
       
        int x=0;
        if(st1.size()==0)return -1;
        else if(st1.size()==1){
            x=st1.top();
            st1.pop();
        }
        else{
            int size=st1.size()-1;
            while(size--){
                st2.push(st1.top());
                st1.pop();
            }
            x=st1.top();
            st1.pop();
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        return x;
    }

    int peek() {
        
        int x=0;
        if(st1.size()==0)return -1;
        else if(st1.size()==1){
            x=st1.top();
        }
        else{
        int size=st1.size()-1;
        while(size--){
            st2.push(st1.top());
            st1.pop();
        }
        x=st1.top();
        st1.pop();
        st2.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        }
        return x;
    }

    bool isEmpty() {
        
        return st1.size()==0;
    }
};
