/**
 * Get the "Balance Factor" of node x
 * BalFact = h(x->left) - h(x->right);
 */
int AVL_Tree::BalFact(TreeNode * x)
{
    if(x->left == nullptr && x->right == nullptr)
        return 0;
    else if(x->left != nullptr && x->right == nullptr)
        return x->left->stature;
    else if(x->left == nullptr && x->right != nullptr)
        return -x->right->stature;
    else
        return x->left->stature - x->right->stature;
}
/**
 * Left rotate the subtree
 * @param x : The root of the subtree to be rotated
 */
void AVL_Tree::Left_Rotate(TreeNode *x)
{
    if(x->right == nullptr)
        return;

    TreeNode * y = x->right;    //Set y
    x->right = y->left;     //Turn y's left subtree into x's subtree

    if(y->left!=nullptr)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;  //Link x's parent to y

    if(x->parent == nullptr)
    {
        root = y;
    }
    else if(x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    y->left = x;    //Put x on y's left
    x->parent = y;
}
/**
 * Right rotate the subtree
 * Symmetry with the function "Left Rotate" above.
 * @param x : The root of the subtree to be rotated
 */
void AVL_Tree::Right_Rotate(TreeNode *y)
{
    if(y->left == nullptr)
        return;

    TreeNode *x = y->left;
    y->left = x->right;

    if(x->right != nullptr)
    {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if(y->parent == nullptr)
    {
        root = x;
    }
    else if(y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}
