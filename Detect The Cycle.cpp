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
#include <map>
bool detectCycle(Node *head){
	
    map <Node* , bool> visited;
    
    Node* temp = head;
    
    while(temp != NULL){
        if(visited[temp]  == true){
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    
    return false;
}

// Time Complexity -> O(N)
// Space Complexity -> O(N)




// Floyd Cycle Detection Algorithm  ->  Hare Tortoise Algorithm
// using pointer approach fast and slow pointer
bool detectCycle(Node *head){

    if (head == NULL || head -> next == NULL) return false;
    
    Node* fast = head; 
    Node* slow = head;
    
    while(fast != NULL)
    {
        
        fast = fast -> next;
        
        if(fast != NULL){
            fast = fast -> next;
        }
        
        slow = slow -> next;
        
        if( slow == fast) {
            return true;
        }
    }
   return false;
}


// Time Complexity - o(N)
// Space Complexity - O(1)
