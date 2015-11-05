/**
 * The Binary Search Tree Data Structure in C++
 * Time Cost : Inorder / Preorder / Postorder Traversal : O(n)
 *             Search / Find / Insert / Delete / Minimum / Maximum : O(h)
 *             Transplant / Rotation : O(1)
 * Thanks to Introduction to Algorithms (CLRS) Chapter 13
 * Thanks to Stanford MOOC of "Algorithms : Part I"
 * Author: Zheng Chen / Arclabs001
 * Email : chenzheng17@yahoo.com
 * Copyright 2015 Xi'an University of Posts & Telecommunications. All rights reserved.
 */
#include <iostream>
#include <stack>
#include <cstdlib>
#define INF 0x7FFFFFFF
using namespace std;

enum COLOR {RED, BLACK};

struct TreeNode {
    int key;
    TreeNode *parent;
    TreeNode *left, *right;
    COLOR color;

    TreeNode& operator = (TreeNode& node)  //Reload the "=" for assignment
    {
        this->key = node.key;
        this->parent = node.parent;
        this->left = node.left;
        this->right = node.right;
        this->color = node.color;
        return *this;
    }
};

TreeNode NULL_NODE = {INF,nullptr,nullptr,nullptr,BLACK};

class Red_Black_Tree
{
private:
    TreeNode * root;
    int _size;
    TreeNode * NIL;

    void Left_Rotate(TreeNode *x);
    void Right_Rotate(TreeNode *x);

    //Insertion or deletion may cause red-black tree's quality destroyed
    //So we just try to fix it by this two options. 
    void RB_Insert_FixUp(TreeNode *z);
    void RB_Delete_FixUp(TreeNode *z);

    void Transplant(TreeNode * u, TreeNode * v);

    TreeNode * Tree_Minimum(TreeNode * root);
    TreeNode * Tree_Maximum(TreeNode * root);

public:
    Red_Black_Tree() { _size = 0; NIL = &NULL_NODE; root = &NULL_NODE;}

    void RBTree_Insert(int _key);
    bool RBTree_Delete(int _key);

    void Preorder_Traversal();
    TreeNode * Find(int _key);
};
/**
 * Left rotate the subtree 
 * @param x : The root of the subtree to be rotated
 */
void Red_Black_Tree::Left_Rotate(TreeNode *x)
{
    if(x->right == NIL)
        return;

    TreeNode * y = x->right;    //Set y
    x->right = y->left;     //Turn y's left subtree into x's subtree

    if(y->left!=NIL)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;  //Link x's parent to y

    if(x->parent == NIL)
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
void Red_Black_Tree::Right_Rotate(TreeNode *y)
{
    if(y->left == NIL)
        return;

    TreeNode *x = y->left;
    y->left = x->right;

    if(x->right != nullptr)
    {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if(y->parent == NIL)
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
/**
 * Transplant the subtree u with the subtree v
 */
void Red_Black_Tree::Transplant(TreeNode * u, TreeNode * v)
{
    if(u->parent == NIL)
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

    v->parent = u->parent;
}
/**
 * Find a node whose key value equals to "_key"
 * @param  _key : The key value
 * @return      : If the node exists, return the node. Else, return the NULL_NODE.
 */
TreeNode * Red_Black_Tree::Find(/*TreeNode * root,*/ int _key)  //The circulation version of Search
{
    TreeNode * p = root;

    while(p != NIL && p->key!=_key)
    {
        if(p->key > _key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}

//Get the minimum key in x's posterity and return the pointer to that node
TreeNode * Red_Black_Tree::Tree_Minimum(TreeNode * root)
{
    TreeNode * p = root;

    while(p->left != NIL)
    {
        p = p->left;
    }
    return p;
}

//Get the maximum key in x's posterity and return the pointer to that node
TreeNode * Red_Black_Tree::Tree_Maximum(TreeNode * root)
{
    TreeNode * p = root;

    while(p->right != NIL)
    {
        p = p->right;
    }
    return p;
}

void Red_Black_Tree::Preorder_Traversal(/*TreeNode * root */)   //The circulation version of Preorder Traversal
{
    cout<<"Preorder Traversal : ";
    stack<TreeNode *> TreeNode_Stack;
    TreeNode * p = root;

    while(p!=NIL || !TreeNode_Stack.empty())
    {
        while(p!=NIL)
        {
            TreeNode_Stack.push(p);
            cout<<p->key<<" ";
            if(p->color==BLACK)
                cout<<"BLACK ";
            else
                cout<<"RED ";
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

