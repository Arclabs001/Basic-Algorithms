/**
 * Determine whether x is the left child of its parent
 * @return   True for x is, and false for not.
 */
bool Splay_Tree::isLeftChild(TreeNode * x)
{
	return (x->parent && x == x->parent->left) ? true : false;
}
/**
 * Splay the TreeNode x onto the root
 * @param x   The node to be splayed
 */
void Splay_Tree::Splay(TreeNode * x)
{
	if(x == nullptr || x == root)
		return;

	while(x != root)
	{
		if(x->parent == root)
		{
			if(isLeftChild(x))
				Right_Rotate(x->parent);
			else
				Left_Rotate(x->parent);
		}
		else
		{
			if(isLeftChild(x))
			{
				if(isLeftChild(x->parent))
				{
					Right_Rotate(x->parent->parent);
					Right_Rotate(x->parent);
				}
				else
				{
					Left_Rotate(x->parent->parent);
					Right_Rotate(x->parent);
				}
			}
			else
			{
				if(isLeftChild(x->parent))
				{
					Right_Rotate(x->parent->parent);
					Left_Rotate(x->parent);
				}
				else
				{
					Left_Rotate(x->parent);
					Left_Rotate(x->parent);
				}
			}
		}
	}
}
