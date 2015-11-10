#include <iostream>
/**
 * Nothing was changed but to splay the new node when finished insersion.
 */
void Splay_Tree::Tree_Insert(int _key)
{
	TreeNode * z = new TreeNode;
    z->key = _key; z->left = z->right = nullptr;

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
        root = z;

    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }

    Splay(z);
    _size++;
}
/**
 * Delete the node valued key
 * Nothing was changed but to splay the new node when finished deletion.
 * @return      True for succeed, and false for failed deleting.
 */
bool Splay_Tree::Tree_Delete(int _key)
{
    TreeNode * z = Tree_Search(_key);
    if(z == nullptr)
    {
        std::cout<<"Error : No node valued "<<_key<<" !"<<std::endl;
        return false;
    }

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
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z, y);

        y->left = z->left;
        y->left->parent = y;
        Splay(y);
    }

    delete z;
    --_size;
    return true;
}
