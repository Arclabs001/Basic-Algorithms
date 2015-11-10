#include <iostream>
#include <stack>
using namespace std;
/**
 * The circulation version of Preorder Traversal
 * Nothing was changed in Splay Tree
 */
void Splay_Tree::Preorder_Traversal(/*TreeNode * root */)
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
