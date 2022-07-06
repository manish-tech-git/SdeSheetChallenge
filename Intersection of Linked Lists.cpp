/********************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

********************/
      
Node* intersect_ll(Node* L1, Node *L2){
    
    
    Node* firstHead = L1;
    Node* secondHead = L2;
    
    Node* newNode = new Node(-1);
    Node* head = newNode;
    
    while (firstHead != NULL && secondHead != NULL)
    {
        
        if(firstHead -> data == secondHead -> data){
            newNode -> next = new Node(secondHead -> data);
                newNode = newNode -> next;
                firstHead = firstHead -> next;
                secondHead = secondHead -> next; 
        }
        
        else if(firstHead  -> data > secondHead -> data){
            secondHead = secondHead -> next;
        }
        else{
            firstHead = firstHead -> next;
        }
        
           
        
    }
    
     return head->next;
}
