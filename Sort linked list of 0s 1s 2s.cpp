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
