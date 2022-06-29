/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode <int> *solve(vector <int> & arr, int st, int end)
{
    if(st> end)
        return NULL;
    int mid = (st+end)/2;
    
    TreeNode <int> *NODE = new TreeNode <int> (arr[mid]);
    
    NODE -> left = solve(arr, st, mid-1);
    NODE -> right = solve (arr, mid+1, end);
    
    return NODE;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    if (n == 0) return NULL;
    return solve(arr, 0, n-1);
}



//Time Complexity: O(n), where n is the total number of nodes in the tree. 

//Space Complexity: O(n) for calling recursion using stack.
