#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
   
    Node<int> *head1 = first;
    Node<int> *head2 = second;
    
    Node<int> *newNode = new Node <int>(-1);
    Node <int> *HEAD = newNode;
    
    
    while (head1 != NULL && head2 != NULL)
    {
        
            if( head1 -> data  >= head2 -> data){
                newNode -> next = head2;
                newNode = newNode -> next;
                head2 = head2 -> next;
            }
            else{
                newNode -> next = head1;
                newNode = newNode -> next;
                head1 = head1 -> next;
            }
   }
    
    if(head1 != NULL)
    {
        while (head1 != NULL){
            newNode -> next = head1;
            newNode = newNode -> next;
            head1 = head1 -> next;
        }
    }
    
    if(head2 != NULL)
    {
        while(head2 != NULL){
            newNode -> next = head2;
            newNode = newNode -> next;
            head2 = head2 -> next;
        }
    }
    
    return HEAD -> next; 
}

// Time Complexity -> O(N);
// Space COmplexity -> O(N)
