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

//**************************************  Naive Approach using extra Space Complexity (used a vector for storing elements) *******************************************

#include <bits/stdc++.h>
bool isPalindrome(LinkedListNode<int> *head) {
    
    LinkedListNode<int>* temp = head ;
    vector <int> ans;
    
    while (temp != NULL){
        ans.push_back(temp -> data);
        temp = temp -> next;
    }
    
    int i = 0; 
    int j = ans.size() -1;
    
    while (i < j)                                   
    {
        if (ans[i] != ans[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}


//Time Complexity - O(N)
//Space Complexity - O(N)


//**************************************************  Optimised Approach using Pointer approach  **********************************************************************

#include <bits/stdc++.h>
LinkedListNode<int> *getMid(LinkedListNode<int> * head)
{
    LinkedListNode<int>* fast = head -> next;
    LinkedListNode<int>* slow = head;
    
    while(fast != NULL && fast -> next != NULL){
        
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

LinkedListNode<int>* reverse(LinkedListNode<int> *head)  // Function which give reverse of linked list 
{
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* next = NULL;
    LinkedListNode<int>* curr = head;
    
    while(curr != NULL){
       next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}


bool isPalindrome(LinkedListNode<int> *head) {

    if(head == NULL || head -> next == NULL)  return true;
    
    // find the middle element
    LinkedListNode<int> *middle = getMid(head);
                                                  //                                          middle    temp
    LinkedListNode<int>* temp = middle -> next;   //  State of linked List ->  1 -> 2 - > 3 ->    4 ->     3 -> 2 -> 1 -> NULL
  
    
                                                  
    // Reverse the second halve
    middle -> next = reverse(temp);
                                                 // After the receiving       1 -> 2 -> 3 -> 4 -> 1 -> 2 -> 3 -> NULL
    
    //Comparing the both halves
    LinkedListNode<int>* head1 = head;                //     head1                    head2
    LinkedListNode<int>* head2 = middle -> next;      //       1 ->  2 ->  3 ->  4 ->  1 ->    2 -> 3 ->  NULL
    
    while (head2 != NULL ){
        if (head1 -> data != head2 -> data){
            return false;
        }
        head1  = head1 -> next;
        head2 = head2 -> next;
    }
    
    // Make the original linked list
    temp = middle -> next;
    middle -> next = reverse(temp);
    
    return true;
}


// Time Complexity - O(N)
// Space Complexity - O(1)


