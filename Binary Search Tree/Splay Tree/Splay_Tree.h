/**
 Created on 2015-11-10 20:10:23

 Description :

 Author: ChenZheng / Arc001
 Email : chenzheng17@yahoo.com
 Copyright 2015 Xi'an University of Posts & Telecommunications
*/

struct TreeNode {
    int key;
    TreeNode *parent;
    TreeNode *left, *right;
};


class Splay_Tree
{
private:
    TreeNode * root;
    int _size;
    TreeNode * Tree_Minimum(TreeNode * x);  //Get the minimum key in x's posterity and return the pointer to that node
    TreeNode * Tree_Maximum(TreeNode * x);  //Get the maximum key in x's posterity and return the pointer to that node
    void Transplant(TreeNode * u, TreeNode * v);
    bool isLeftChild(TreeNode * x);
protected:
    void Splay(TreeNode * x);
    void Left_Rotate(TreeNode * x);
    void Right_Rotate(TreeNode* x);

public:
	Splay_Tree() {root = nullptr; _size = 0;}   //Constructor

    void Preorder_Traversal();

	void Tree_Insert(int _key);
	bool Tree_Delete(int _key);
	TreeNode * Tree_Search(int _key);
};

