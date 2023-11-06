#ifndef MYTREE_H_INCLUDED
#define MYTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BK 404
/*the struct of tree node*/
struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};
typedef struct treeNode treeNode;
/*create a new node*/
treeNode *newNode(int item);
/*create and delete a tree*/
treeNode *newTree(treeNode *root,int *arr,int size,int i);
void delTree(treeNode *root);

/*three travel ways*/
void preOrder(treeNode *root);
void inOrder(treeNode *root);
void postOrder(treeNode *root);

bool isFullTree(treeNode *root);

int depth(treeNode *root);
bool isPerfect(treeNode *root,int d,int level);
bool isPerfectTree(treeNode *root);
int numbersOfTree(treeNode *root);
bool isCompleteTree(treeNode *root,int index,int numbers);
bool isHeightBalanceTree(treeNode *root, int *height);

/*BST tree*/
treeNode *BSI_Insert(treeNode *root,int key);
treeNode *BSI_Min(treeNode *root);
treeNode *BSI_delete(treeNode *root,int key);
#endif // MYTREE_H_INCLUDED
