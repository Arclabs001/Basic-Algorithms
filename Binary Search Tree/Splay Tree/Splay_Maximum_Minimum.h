//Get the minimum key in x's posterity and return the pointer to that node
//Nothing was changed in Splay Tree..
TreeNode * Splay_Tree::Tree_Minimum(TreeNode * root)
{
    TreeNode * p = root;

    while(p->left != nullptr)
    {
        p = p->left;
    }
    return p;
}

//Get the maximum key in x's posterity and return the pointer to that node
TreeNode * Splay_Tree::Tree_Maximum(TreeNode * root)
{
    TreeNode * p = root;

    while(p->right != nullptr)
    {
        p = p->right;
    }
    return p;
}
