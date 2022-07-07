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
