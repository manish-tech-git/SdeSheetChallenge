#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

****************************************************************

           slow       fast
 1    ->    2    ->    3    ->    4    ->    5
            |                                |
            |                                |
            ---------------------------------|
     
****************************************************************/


Node *firstNode(Node *head)
{
    if(head == NULL || head -> next == NULL) return NULL;    
    
    Node* slow = head;
    Node* fast = head;
    slow = slow -> next;  // Increament slow pointer
    fast = fast -> next -> next; // Increeament fast pointer
    while(fast && fast -> next)
    {
        if(slow == fast) break;
        slow = slow -> next;
        fast = fast -> next -> next;
   }
    
    if(slow != fast ) return NULL; // if there is no loop in list return NULL
    
    slow = head; // initialise again slow to head for checking matching nodes
    
    while(slow != fast)
    {
        slow = slow -> next;
        fast = fast -> next ;
    }
    
    return slow;
}

// Time Complexity -> O(N)
// SpaceComplexity -> O(1)
