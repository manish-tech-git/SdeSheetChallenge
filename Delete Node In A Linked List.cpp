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

void deleteNode(LinkedListNode<int> * node) {

    // Let us say we have a linked list
    // 1 -> 2 -> 3 -> 4 -> NULL
    //   delete -> node(2)
   
    node -> data = node -> next -> data;
    // Copy the next node data  to the node
    //1 -> 3 -> 3 -> 4 -> NULL
    
     node -> next = node -> next -> next;
    // change the reference node ka next to the node -> next -> next;
    // 1 -> 3 -> 4 -> NULL
}

// Time Complexity -> O(1)
// Space Complexity -> O(1)
