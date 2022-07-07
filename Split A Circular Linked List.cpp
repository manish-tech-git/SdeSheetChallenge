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

void splitCircularList(Node *head)
{
    
    if (head == NULL) return;
    if (head -> next == NULL) cout << head -> data;
    
    Node* temp = head;
    Node* tail = head;
    
    int cnt = 1;
    while(temp -> next != head){
        temp = temp -> next;
        tail = tail -> next;
        cnt++;
    }
    
    int mid = cnt / 2;
    int position = 1; 
    
    temp = head;
    while(position < mid){
        //cout << temp1 -> data <<" ";
        temp = temp -> next;
        position++;
    }
    
    Node* forward = temp -> next;
    temp -> next = head;
    tail -> next = forward;
    
}
