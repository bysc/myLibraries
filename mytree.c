#include "mytree.h"
treeNode *newNode(int item)
{
    treeNode *temp=(treeNode *)malloc(sizeof(treeNode));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}
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
//按节点数算深度，适用于完美和完全二叉树
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
//计算节点数，通用
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
/*BSI结点插入，该方式作为叶子节点插入，返回树*/
treeNode *BSI_Insert(treeNode *root,int key)
{
    if(NULL==root) return newNode(key);//插到叶子节点，但形式并不唯一，只是一种可行的方法
    if(key<root->data) root->left=BSI_Insert(root->left,key);
    else root->right =BSI_Insert(root->right, key);
    return root;//相等的话什么也不做
}
/*BSI的最小值，即为最左下角的节点，返回该节点*/
treeNode *BSI_Min(treeNode *root)
{
    treeNode *current=root;
    while(current&&current->left!=NULL) current=current->left;//不断移到左子树
    return current;
}
/*删除某个节点，返回树的节点*/
treeNode *BSI_delete(treeNode *root,int key)
{
    if(NULL==root) return root;//空树不动
    //常见的递归
    if(key<root->data) root->left=BSI_delete(root->left,key);
    else if(key>root->data) root->right=BSI_delete(root->right,key);
    //删除节点就是当前（子）树根节点时
    else
    {
        //只有一个孩子或者没有孩子，把孩子拿过来即可
        //没有左孩子返回右子树
        if(NULL==root->left)
        {
            treeNode *temp=root->right;//右子树
            free(root);
            return temp;
        }
        //没有右孩子返回左子树
        else if(root->right==NULL)
        {
            treeNode *temp=root->left;//左子树
            free(root);
            return temp;
        }
        //有两个孩子，用右子树最小值覆盖被删节点，再删掉右子树最小值
        else
        {
            treeNode *temp=BSI_Min(root->right);
            root->data=temp->data;
            //不能直接free，因为最小节点不一定是叶子，而且不知道父节点
            root->right=BSI_delete(root->right,temp->data);
        }
    }
    return root;
}
