#include "mytree.h"
treeNode *newTree(treeNode *root,int *arr,int size,int i)
{
    if(i>=size||arr[i]==BK) return NULL;
    root=(treeNode*)malloc(sizeof(treeNode));
    root->data=arr[i];
    root->left=newTree(root->left,arr,size,2*i+1);
    root->right=newTree(root->right,arr,size,2*i+2);
    return root;
}
void delTree(treeNode *root)
{
    if(NULL==root) return;
    delTree(root->left);
    delTree(root->right);
    free(root);
}
void preOrder(treeNode *root)
{
    if(NULL==root) return;
    printf("%d  ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(treeNode *root)
{
    if(NULL==root) return;
    inOrder(root->left);
    printf("%d  ",root->data);
    inOrder(root->right);
}
void postOrder(treeNode *root)
{
    if(NULL==root) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ",root->data);
}
int isFullTree(treeNode *root)
{
    if(NULL==root) return true;
    if(root->left==NULL && root->right==NULL) return true;
    if((root->left)&&(root->right))
        return isFullTree(root->left)&&isFullTree(root->right);
    return false;
}
