
/**
 * Insert a new node into the RB-Tree
 * @param _key : the key value of the new node
 */
void Red_Black_Tree::RBTree_Insert(int _key)
{
    TreeNode * z = new TreeNode;
    z->key = _key;
    z->color = RED;
    z->left = z->right = NIL;

    TreeNode *y = NIL;
    TreeNode *x = root;

    while(x != NIL)
    {
        y = x;
        if(_key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if(y == NIL)
    {
        root = z;
    }
    else if(z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }

    RB_Insert_FixUp(z);
}
/**
 * Fix the double-red bug in this tree
 * @param z : a node which was just inserted
 */
void Red_Black_Tree::RB_Insert_FixUp(TreeNode *z)
{
    while(z->parent->color == RED)
    {
        if(z->parent == z->parent->parent->left)
        {
            TreeNode * y = z->parent->parent->right;
            if(y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->right)
                {
                    z = z->parent;
                    Left_Rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                Right_Rotate(z->parent->parent);
            }
        }
        else
        {
            TreeNode * y = z->parent->parent->left;
            if(y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->left)
                {
                    z = z->parent;
                    Right_Rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                Left_Rotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}
/**
 * Delete a node from the RB-Tree
 * @param  _key : The key value of the node which is to deleted
 * @return      : True for succeed, and false for no such node existed.
 */
bool Red_Black_Tree::RBTree_Delete(int _key)
{
    TreeNode *z = Find(_key);
    if(z == NIL)
    {
        cout<<"Error : No node valued "<<_key<<" !"<<endl;
        return false;
    }

    TreeNode *y = z;
    COLOR y_original_color = y->color;

    TreeNode *x;
    if(z->left == NIL)
    {
        x = z->right;
        Transplant(z,z->right);
    }
    else if(z->right == NIL)
    {
        x = z->left;
        Transplant(z,z->left);
    }
    else
    {
        y = Tree_Minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            Transplant(y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        Transplant(z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if(y_original_color == BLACK)
        RB_Delete_FixUp(x);

    delete z;
    return true;
}
/**
 * Delete a node may cause Black-Height changed, and this function is to fix this bug.
 * @param x : The place where the substitude node used to be
 */
void Red_Black_Tree::RB_Delete_FixUp(TreeNode *x)
{
    while(x!=root && x->color == BLACK)
    {
        if(x == x->parent->left)
        {
            TreeNode *w = x->parent->right;
            if(w->color == RED)
            {
                w->color = BLACK;
                w->parent->color = RED;
                Right_Rotate(w);
                w = x->parent->right;
            }

            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if(w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    Right_Rotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                Left_Rotate(x->parent);
                x = root;
            }
        }
        else
        {
            TreeNode *w = x->parent->left;
            if(w->color == RED)
            {
                w->color = BLACK;
                w->parent->color = RED;
                Left_Rotate(w);
                w = x->parent->left;
            }

            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if(w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    Left_Rotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                Right_Rotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}
