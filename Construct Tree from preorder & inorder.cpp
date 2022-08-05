/***********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
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

***********************************************************/


int findPosition (int *inorder, int element, int n)
{
        for (int i = 0; i< n; i++)
        {
            if (inorder[i] == element)
            return i;
        }
        
        return -1;
}




BinaryTreeNode<int>*  solve (int *inorder, int *preorder, int &index, int st, int end, int n)
{
    //Base Case
    if (index >= n || st > end)
        return NULL;
    
    int element = preorder[index++];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(element);
    int position = findPosition (inorder, element, n);
    
    // Recursive Calls
    root -> left = solve (inorder, preorder, index, st, position - 1, n);
    root -> right = solve (inorder, preorder, index, position + 1, end, n);
    
    return root;
    
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int n) 
{
    
    int  preOrderindex = 0;
    BinaryTreeNode<int>* ans = solve (inorder, preorder, preOrderindex, 0, n-1, n );
    return ans;
    
    
}




