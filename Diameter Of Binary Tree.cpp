/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int solve(TreeNode<int> * root, int &diameter)
{
    if(!root) return -1;
    
    int left = 1 + solve(root -> left, diameter);
    int right = 1 + solve(root -> right , diameter);
    diameter = max(diameter, left+right);
    return  max(left, right);
    
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diameter = 0;
    solve(root, diameter );
    return diameter;
    
    
    
}
