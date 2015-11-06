/**
 * The Adelson-Velskii and Landis(AVL) Tree Data Structure in C++
 * Time Cost : Inorder / Preorder / Postorder Traversal : O(n)
 *             Search / Find / Insert / Delete / Minimum / Maximum : O(logn)
 *             Transplant / Rotation : O(1)
 * Thanks to Introduction to Algorithms (CLRS) Chapter 13
 * Author: Zheng Chen / Arclabs001
 * Email : chenzheng17@yahoo.com
 * Copyright 2015 Xi'an University of Posts & Telecommunications. All rights reserved.
 */

struct TreeNode {
    int key;
    int stature;
    //stature holds the distance of the longest path from this node to its descendant leaf node
    TreeNode *parent;
    TreeNode *left, *right;

    TreeNode& operator = (TreeNode& node)  //Reload the "=" for assignment
    {
        this->key = node.key;
        this->parent = node.parent;
        this->left = node.left;
        this->right = node.right;
        return *this;
    }
};

class AVL_Tree
{
private:
    TreeNode * root;
    int _size;

    TreeNode * Tree_Minimum(TreeNode * x);  //Get the minimum key in x's posterity and return the pointer to that node
    TreeNode * Tree_Maximum(TreeNode * x);  //Get the maximum key in x's posterity and return the pointer to that node

    void Left_Rotate(TreeNode * x);
    void Right_Rotate(TreeNode* x);

    int BalFact(TreeNode * x);  //Get the 'balance factor' of node x
    void UpdateStature(TreeNode * x);
    bool AVLBalanced(TreeNode * x) { return (-2 < BalFact(x)) && (BalFact(x) < 2); }

    void Transplant(TreeNode * u, TreeNode * v);

public:
    AVL_Tree() {root = nullptr; _size = 0;}
	void AVL_Tree_Insert(int _key);
	void AVL_Tree_Delete(int _key);

	void AVL_FixUp(TreeNode * x);

	void Preorder_Traversal();
	void Preorder_Tree_Walk_Stature();
	void Preorder_Tree_Walk_Stature_(TreeNode * root);

	TreeNode * Find(int _key);
};
