/********************************
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

********************************/

Node* sortList(Node *head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    Node* temp = head ;
    
    while (temp != NULL){
        if (temp -> data == 0)
            zeroCount += 1;
        else if (temp -> data == 1)
            oneCount += 1;
        else 
            twoCount += 1;
        
        temp = temp -> next;
    }
    
    temp = head ;
    
    while (temp != NULL){
        
        if (zeroCount != 0){
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp -> data = 1;
            oneCount--;
        }
        else{
            temp -> data = 2;
            twoCount--;
        }
        
        temp = temp -> next;
    }
    
    return head;
 }




// Time Complexity - O(N)
// Space Complexity - O(1)




// Approach 2  - when the nodes replacement of nodes is not allowed

/********************************
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

********************************/

void insertAtTail (Node* &tail, Node* curr)
{
    tail -> next = curr;
    tail = curr;
    
    
}

Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    //Create seperate list 
    while (curr != NULL)
    {
        
        int value = curr -> data;
        
        if(value == 0){
            insertAtTail(zeroTail, curr);
        }
        
        else if (value == 1){
            insertAtTail (oneTail, curr);
        }
        else{
            insertAtTail (twoTail, curr);
        }
        
        curr = curr -> next;
    }
    
    //Merge Linked List
    
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else{
        //1s list
        zeroTail -> next = twoHead -> next;
        
    }
    oneTail -> next =   twoHead -> next;
    twoTail -> next = NULL;
    
    //setup head
    head = zeroHead ->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;

}


// Time Complexity - O(N)
// Space Complexity - O(1)



