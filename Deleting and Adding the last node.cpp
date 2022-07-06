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

Node *delAddLastNode(Node *head){
    while (head == NULL || head -> next == NULL)
        return head;
    
    
	Node* temp = head;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    
    Node* curr = head;
    while (curr -> next != temp){
        curr = curr -> next;
    }
    temp -> next = NULL;
    curr -> next = NULL;
    
    temp-> next = head;
    head = temp;
    return head;
    
}

// Time Complexity - O(N)
// Space Complexity - O(1)



