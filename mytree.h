#ifndef MYTREE_H_INCLUDED
#define MYTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BK 404
struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};
typedef struct treeNode treeNode;
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
#endif // MYTREE_H_INCLUDED
