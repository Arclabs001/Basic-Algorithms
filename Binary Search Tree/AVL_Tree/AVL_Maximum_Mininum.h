/**
 * Get the maximum key in x's posterity and return the pointer to that node
 */
TreeNode * AVL_Tree::Tree_Maximum(TreeNode * root)
{
    TreeNode * p = root;

    while(p->right != nullptr)
    {
        p = p->right;
    }
    return p;
}

/**
 * Get the minimum key in x's posterity and return the pointer to that node
 */
TreeNode * AVL_Tree::Tree_Minimum(TreeNode * root)
{
    TreeNode * p = root;

    while(p->left != nullptr)
    {
        p = p->left;
    }
    return p;
}

/**
 * The circulation version of Search
 * Search for a node valued _key
 * @return      The pointer to the target node
 */
TreeNode * AVL_Tree::Find(/*TreeNode * root,*/ int _key)  
{
    TreeNode * p = root;

    while(p != nullptr && p->key!=_key)
    {
        if(p->key > _key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}
