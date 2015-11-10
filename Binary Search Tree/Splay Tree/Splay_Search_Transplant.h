/**
 * The circulation version of Search
 * Search for a node valued _key
 * @return      The pointer to the target node
 */
TreeNode * Splay_Tree::Tree_Search(int _key)
{
	TreeNode * p = root;

    while(p != nullptr && p->key!=_key)
    {
        if(p->key > _key)
            p = p->left;
        else
            p = p->right;
    }
    Splay(p);
    return p;
}
/**
 * Replace the subTree rooted u with the subTree v
 */
void Splay_Tree::Transplant(TreeNode * u, TreeNode * v)
{
    if(u->parent == nullptr)
    {
        root = v;
    }
    else if(u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }

    if(v != nullptr)
        v->parent = u->parent;
}
