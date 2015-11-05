#include "BST.h"
int _arr[] = {12,5,18,2,9,15,19,17};

int main()
{
    Binary_Search_Tree T;   //Test the Constructor
    for(int i=0; i<8; i++)
    {
        T.Tree_Insert(_arr[i]);    //Test the Insert function
    }

    T.Inorder_Traversal();    //Test the inorder traversal function
    T.Tree_Insert(13);
    T.Inorder_Traversal();

    TreeNode * tmp = T.Tree_Successor(T.Find(2));   //Test the Search and Successor function
    cout<<endl<<"The Node after "<<2<<" in the inorder traversal order is : "<<tmp->key<<endl;
    tmp = T.Tree_getMaximum();    //Test the maximum function
    cout<<"The largest node is : "<<tmp->key<<endl<<endl;
    T.Tree_Delete(9);   //Test the delete function

    T.Inorder_Traversal();      //Test the inorder traversal function
    T.Preorder_Traversal();     //Test the preorder traversal function
    T.Postorder_Traversal();    //Test the postorder traversal function

    cout<<endl;
    T.Tree_Delete(1);   //Test the delete function when there is no node valued "1".
    return 0;
}
