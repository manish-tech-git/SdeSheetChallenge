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
