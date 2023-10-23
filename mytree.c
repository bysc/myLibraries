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
bool isFullTree(treeNode *root)
{
    if(NULL==root) return true;
    if(root->left==NULL && root->right==NULL) return true;
    if((root->left)&&(root->right))
        return isFullTree(root->left)&&isFullTree(root->right);
    return false;
}
//按节点数算深度
int depth(treeNode *root)
{
    int d=0;
    while (root!=NULL)
    {
        d++;
        root=root->left;
    }
    return d;
}
bool isPerfect(treeNode *root,int d,int level)
{
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return (d==level+1);//叶子结点
    if(root->left==NULL || root->right==NULL) return false;
    return isPerfect(root->left,d,level+1)&&isPerfect(root->right,d,level+1);
}
bool isPerfectTree(treeNode *root)
{
    int d=depth(root);
    return isPerfect(root,d,0);
}
int numbersOfTree(treeNode *root)
{
    if(root==NULL) return 0;
    return (1+numbersOfTree(root->left)+numbersOfTree(root->right));
}
bool isCompleteTree(treeNode *root,int index,int numbers)
{
    if(root==NULL) return true;
    if(index>=numbers) return false;
    return isCompleteTree(root->left,2*index+1,numbers)&&isCompleteTree(root->right,2*index+2,numbers);
}
bool isHeightBalanceTree(treeNode *root, int *height)
{
    int leftHeight=0,rightHeight=0;
    int l=0,r=0;
    if(root==NULL)
    {
        *height=0;
        return true;
    }
    l=isHeightBalanceTree(root->left,&leftHeight);
    r=isHeightBalanceTree(root->right,&rightHeight);
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2)) return false;
    else return l && r;
}
