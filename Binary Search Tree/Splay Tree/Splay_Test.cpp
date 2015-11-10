#include "Splay_Test.h"
int main()
{
    Splay_Tree splay;
    for(int i=0; i<10; i++)
        splay.Tree_Insert(i);

    splay.Preorder_Traversal();

    splay.Tree_Search(3);
    splay.Tree_Search(1);
    splay.Tree_Delete(6);

    splay.Preorder_Traversal();

    return 0;
}
