#include <bits/stdc++.h> 
/********************************

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

********************************/
Node *rotate(Node *head, int k) {
    
     if (head ==  NULL || head -> next == NULL || k == 0) return head;
        
        //compute the length
        Node *cur = head;
        int len = 1;
        while (cur -> next != NULL){
            len++;
            cur = cur -> next;
        }
        
        
        // go till that node 
        cur -> next = head;
        k = k % len;
        k = len - k;
        
        while (k-- > 0) cur = cur -> next;
        
        // make the node head and break connections
        head = cur -> next;
        cur -> next = NULL;
        
        return head;

}



// Time Complexity -> O(N)
// Space Complexity -> O(1)
