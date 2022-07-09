#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/

Node* merge(Node* a,Node* b)
{
    Node* temp=new Node(1); // Initialse answer linked list
    Node* res=temp;
    
    while(a!=NULL && b!=NULL)
    {
        if(a->data<=b->data)
        {
            temp->child=a;
            a=a->child;
            temp=temp->child;
            temp->next=NULL;
        }
        else
        {
            temp->child=b;
            b=b->child;
            temp=temp->child;
            temp->next=NULL;
        }
    }
    if(a!=NULL)
        temp->child=a;
    if(b!=NULL)
        temp->child=b;
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
    
    if(head==NULL || head->next==NULL)
        return head;
    
    
    head->next=flattenLinkedList(head->next);
    
    return merge(head,head->next);
}
