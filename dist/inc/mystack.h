#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define STACK_MAXSIZE 100
#define STACK_ELEM int
//-------链栈结构体---------------------------
typedef struct linkListStackNode
{
    STACK_ELEM var;
    struct linkListStackNode *next;
}linkListStackNode;
typedef struct linkListStack
{
    linkListStackNode *top;//栈顶
    int size;
}linkListStack;
//--------------------------------------------

//-------顺序栈---------------------------------

linkListStack *newLinkListStack();//构造函数
void deLinkListStack(linkListStack *s);//析构函数
int sizeofLinkListStack(linkListStack*s);//栈长
STACK_ELEM peekofLinkListStack(linkListStack*s);//栈顶
void linkListStackPush(linkListStack *s, STACK_ELEM elem);//入栈
STACK_ELEM linkListStackPop(linkListStack *s);//出栈
#endif // MYSTACK_H_INCLUDED
