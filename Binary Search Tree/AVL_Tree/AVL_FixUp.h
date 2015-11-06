/**
 * Fix the tree when it's unbalanced
 * @param x [from where up]
 */
void AVL_Tree::AVL_FixUp(TreeNode * x)
{
	if(x==nullptr)
		return;

    UpdateStature(x);
	if(BalFact(x) < -1)
	{
		Left_Rotate(x);
		UpdateStature(x);
		x = x->parent;
		x->stature = std::max(1+ x->left->stature, 1+ x->right->stature);
	}
	else if(BalFact(x) > 1)
	{
		Right_Rotate(x);
		UpdateStature(x);
		x = x->parent;
		x->stature = std::max(1+ x->left->stature, 1+ x->right->stature);
	}
	AVL_FixUp(x->parent);
}
/**
 * Update the stature of node x
 */
void AVL_Tree::UpdateStature(TreeNode * x)
{
    if(x == nullptr)
        return;

    if(x->left == nullptr && x->right == nullptr)
    {
        x->stature = 1;
    }
    else if(x->left == nullptr && x->right != nullptr)
    {
        x->stature = 1+x->right->stature;
    }
    else if(x->left != nullptr && x->right == nullptr)
    {
        x->stature = 1+x->left->stature;
    }
    else
    {
        x->stature = std::max(1+ x->left->stature, 1+ x->right->stature);
    }
}
