/**
 * Insert a node valued _key into the tree
 */
void AVL_Tree::AVL_Tree_Insert(int _key)
{
    TreeNode * z = new TreeNode;
    z->key = _key; z->left = z->right = nullptr; z->stature = 1;

    TreeNode * x = root;
    TreeNode * y = nullptr;

    while(x!=nullptr)   //Find the parent of the new node
    {
        y = x;
        if(z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    z->parent = y;

    if(y==nullptr)  //When the tree is empty
    {
        root = z;
        y = z;
    }

    else if (z->key < y->key)
    {
        y->left = z;

        if(y->right == nullptr)
        	y->stature = 2;
        else
        	y->stature = std::max(2,1+y->right->stature);
    }
    else
    {
        y->right = z;

        if(y->left == nullptr)
        	y->stature = 2;
        else
        	y->stature = std::max(2,1+y->left->stature);
    }

    AVL_FixUp(y->parent);
    _size++;
}
/**
 * Delete the nearest node from root which valued _key
 */
void AVL_Tree::AVL_Tree_Delete(int _key)
{
    TreeNode * z = Find(_key);
    if(z == nullptr)
    {
        std::cout<<"Error : No node valued "<<_key<<" !"<<std::endl;
        return;
    }

    TreeNode * x = z->parent;
    if(z->left == nullptr)
    {
        Transplant(z, z->right);
    }
    else if(z->right == nullptr)
    {
        Transplant(z, z->left);
    }
    else
    {
        TreeNode * y = Tree_Minimum(z->right);
        if(y->parent != z)
        {
            x = y->parent;
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z, y);

        y->left = z->left;
        y->left->parent = y;
        UpdateStature(y);
    }

    delete z;
    --_size;
    AVL_FixUp(x);
}
/**
 * Replace the subTree rooted u with the subTree v
 */
void AVL_Tree::Transplant(TreeNode * u, TreeNode * v)
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
