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

int getMaxWidth(TreeNode<int> *root)
{
   if(root == NULL) return 0;
    
    queue <TreeNode<int>*> q;
    q.push(root);
    int count = 0;
    while(!q.empty())
    {
       int n = q.size();
        count = max(count , n);
        
        
        for (int i = 0; i< n; i++)
        {
            TreeNode <int> * node = q.front();
            q.pop();
            
            if(node-> left)   q.push(node-> left);
            if(node -> right) q.push(node -> right);
        }
    }
    return count;
}
