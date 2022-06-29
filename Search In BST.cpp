/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/



bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    
   if(root == NULL) return false;
    
    if(root -> data == x)
        return true;
    
    if(root -> data < x)
        return searchInBST(root -> right,x);
    
    else{
        return searchInBST(root -> left,x);
    }
    
}



/*
OPERATION 	WORST CASE	 AVERAGE CASE	 BEST CASE	 SPACE
Search	   O(N)	          O(logN)	       O(1)	        O(N)
Insert	   O(N)	          O(logN)	       O(1)	        O(N)
Delete	   O(N)	          O(logN)	       O(N)	        O(N)

*/
