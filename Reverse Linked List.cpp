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

//Iterative Approach 

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head -> next == NULL) return head;
    
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int> * curr = head;
    LinkedListNode<int> * forward = NULL;
    
    while (curr != NULL)
    {
        // Storing the address of next node 
        forward = curr -> next;
        // point the current node to the prev or (null for first case)
        curr -> next = prev;
        // increase the prev pointer
        prev = curr;
        // increase the current pointer
        curr = forward;
    }
    
    return prev;
 }


//Time Complexity - O(N)


// Iterative approach


void reverse (LinkedListNode<int>* &head,LinkedListNode<int> *curr,LinkedListNode<int> *prev)
{
    //Base case
    if(curr == NULL){
        head = prev;
        return;
    }
    
    LinkedListNode<int> *forward = curr -> next;
    reverse (head, forward, curr);
    curr -> next = prev;
}



LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* prev = NULL;
    reverse (head, curr, prev);
    return head;
    
    
}


