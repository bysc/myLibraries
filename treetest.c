#include "treetest.h"
void testTreeTravel()
{
    int arr[]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    treeNode *root=NULL;
    root=newTree(root,arr,17,0);
    printf("\npreOrder:\n");
    preOrder(root);
    printf("\ninOrder:\n");
    inOrder(root);
    printf("\npostOrder:\n");
    postOrder(root);
//    printf("\nthe tree is a full tree?--%d",isFullTree(root));
    delTree(root);
}
