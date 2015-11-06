using namespace std;
/**
 * The circulation version of Preorder Traversal
 */
void AVL_Tree::Preorder_Traversal(/*TreeNode * root */)   
{
    cout<<"Preorder Traversal : ";
    stack<TreeNode *> TreeNode_Stack;
    TreeNode * p = root;

    while(p!=nullptr || !TreeNode_Stack.empty())
    {
        while(p!=nullptr)
        {
            TreeNode_Stack.push(p);
            cout<<p->key<<" ";
            p = p->left;
        }
        if(!TreeNode_Stack.empty())
        {
            p = TreeNode_Stack.top();
            TreeNode_Stack.pop();
            p = p->right;
        }
    }
    cout<<endl;
}

/**
 * The recursion version of Preorder Traversal
 * Print the stature of each node in preorder
 */
void AVL_Tree::Preorder_Tree_Walk_Stature()
{
    if(root != nullptr)
    {
        cout<<root->stature<<" ";
        Preorder_Tree_Walk_Stature_(root->left);
        Preorder_Tree_Walk_Stature_(root->right);
    }
}

void AVL_Tree::Preorder_Tree_Walk_Stature_(TreeNode * root)
{
    if(root != nullptr)
    {
        cout<<root->stature<<" ";
        Preorder_Tree_Walk_Stature_(root->left);
        Preorder_Tree_Walk_Stature_(root->right);
    }
}
