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

*****************************************************************/

bool circularLL(Node* head)
{
   
    
    Node* temp = head;
    
    while(temp != NULL)
    {
        if( temp -> next == head) return true;
        temp = temp -> next;
    }
    return false;
}
