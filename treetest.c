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
void testTreeType()
{
    int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int size=10;
    int numbers=0;
    treeNode *root=NULL;
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    root=newTree(root,arr,size,0);
    numbers=numbersOfTree(root);
    printf("\nthis is a perfect tree?: %d",isPerfectTree(root));
    printf("\nthis is a complete tree?:%d\n",isCompleteTree(root,0,numbers));
    delTree(root);
    size=15;
        for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    root=newTree(root,arr,size,0);
    numbers=numbersOfTree(root);
    printf("\nthis is a perfect tree?: %d",isPerfectTree(root));
    printf("\nthis is a complete tree?:%d\n",isCompleteTree(root,0,numbers));
    delTree(root);
}
