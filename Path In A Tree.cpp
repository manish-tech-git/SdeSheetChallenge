/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool solve (TreeNode<int> *root, vector <int> &ans, int x  )
{
    if (root == NULL)
        return false;
    
    if (root -> data == x){
        ans.push_back(x);
        return true;
    }
    
    ans.push_back (root -> data);
    
    if (solve (root -> left, ans, x) || solve (root -> right, ans, x))
        return true;

    
    ans.pop_back();
    
    return false;
}


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector <int> ans;
    solve (root, ans, x);
    return ans;
   
}


