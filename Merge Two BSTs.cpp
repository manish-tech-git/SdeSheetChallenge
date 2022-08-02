/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/


void inorder (TreeNode<int> *root, vector <int> &ans)
{
    if (root == NULL) return;
    
    inorder (root -> left, ans);
    ans.push_back (root -> data);
    inorder (root -> right, ans);
    
}

vector <int> mergeArray (vector <int> &arr1, vector <int> &arr2)
{
    
     int i = 0, j = 0;
    vector<int> arr;
    
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr.push_back(arr1[i]);
            i++;
        } else {
            arr.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < arr1.size()) {
        arr.push_back(arr1[i]);
        i++;
    }
    
    while (j < arr2.size()) {
        arr.push_back(arr2[j]);
        j++;
    }
    
    return arr;
    
}

TreeNode<int> *solve (vector <int> &result, int st, int end)
{
    if (st > end) return NULL;
    
    int mid = (st + end) / 2;
    
    TreeNode<int>* root = new TreeNode<int>(result[mid]);
    
    root -> left = solve (result , st, mid - 1);
    
    root ->right = solve (result, mid + 1, end);
    
    return root;
    
}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    //Step 1 Store inorder of root1
    vector <int> ans1;
    inorder (root1, ans1);
    
    //Step 2 Store inorder of root2
    vector <int> ans2;
    inorder (root2, ans2);
    
    
    // Merge both vectors
    vector <int> result = mergeArray (ans1, ans2);
    
   return solve (result, 0, result.size()-1);
    
}


// Time Complexity ->  O(N+M)
// Space Complexity -> O(N+M)








