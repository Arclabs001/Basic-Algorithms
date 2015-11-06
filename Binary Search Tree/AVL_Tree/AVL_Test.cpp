#include "AVL_Test.h"

int main()
{
    AVL_Tree AVLTREE;
    for(int i=15; i>0; i--)
        AVLTREE.AVL_Tree_Insert(i);

    AVLTREE.Preorder_Traversal();
    cout<<"Stature in Preorder: ";
    AVLTREE.Preorder_Tree_Walk_Stature();
    cout<<endl;

    cout<<endl<<"Now delete node valued 1 to 6"<<endl<<endl;
    for(int i=1; i<=6; i++)
        AVLTREE.AVL_Tree_Delete(i);

    AVLTREE.Preorder_Traversal();
    cout<<"Stature in Preorder: ";
    AVLTREE.Preorder_Tree_Walk_Stature();
    cout<<endl;
    return 0;
}
