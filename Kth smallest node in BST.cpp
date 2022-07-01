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
void solve(TreeNode<int> * root , int &k, int &count)
{
    if(root == NULL) return ;
    
    solve(root -> left, k, count);
    k--;
    if(k == 0){
        count = root -> data;
        return;
    }
    solve(root -> right, k ,count);
    
    
}

int kthSmallest(TreeNode<int> *root, int k)
{
    
    int count = 0;
    solve(root , k , count);
    return count;
}


