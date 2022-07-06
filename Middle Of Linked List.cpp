#include <bits/stdc++.h> 
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

Node *findMiddle(Node *head) {
    
    if(head == NULL || head -> next == NULL)
        return head;
    
    int cnt = 0;
    Node* temp  = head ;
    
    while (temp != NULL){
        cnt += 1;
        temp = temp -> next;
    }
    Node* find = head;
    int mid = cnt/2;
    int position = 0; 
    while(position < mid)
    {
        find = find -> next;
        position++;
    }
    
    return find;
    
}


