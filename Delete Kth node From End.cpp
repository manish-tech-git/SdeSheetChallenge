#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if (head == NULL || K == 0) return head;
    // finding the size of linked list
    int cnt = 0;
    LinkedListNode<int>* temp = head;
    
    
    while(temp != NULL){
        cnt++;
       temp = temp -> next;
    }
    
    temp = head;
    K = cnt - K;
    
    LinkedListNode<int>* prev = NULL;
    
    while ( K > 0){
        prev = temp ;
        temp = temp -> next;
        K--;
    }    
    
    if (prev != NULL){
        //LinkedListNode<int>* forward = temp -> next;
        prev -> next = temp -> next;
        //delete (temp);
    }
    else {
        head = head -> next;
    }
  return head;
}

//Time Complexity - O(N)
//Space Complexity - O(1)
