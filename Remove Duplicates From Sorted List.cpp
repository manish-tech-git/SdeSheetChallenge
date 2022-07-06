/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/
/*

temp
1 ->  2 ->  2-> 3 -> NULL

if temp ka data equal to temp ke next data then we have change the temp -> next 
address 

temp -> next = temp -> next -> next

*/



Node * uniqueSortedList(Node * head) {
    
    if (head == NULL || head -> next == NULL) return head;
    
    Node* temp = head;
    while (temp -> next != NULL)
    {
        if(temp -> data == temp -> next -> data)
            temp -> next = temp -> next -> next;
        else 
            temp = temp -> next;
    }
    return head;
}
