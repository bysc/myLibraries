#include "mystack.h"
linkListStack*newLinkListStack()
{
    linkListStack*s=(linkListStack*)malloc(sizeof(linkListStack));
    s->size=0;
    s->top=NULL;
    return s;
}
void deLinkListStack(linkListStack *s)
{
    linkListStackNode *backup=NULL;
    while(s->top)
    {
        backup=s->top->next;
        free(s->top);
        s->top=backup;
    }
    free(s);
}
int sizeofLinkListStack(linkListStack*s)
{
    return s->size;
}
STACK_ELEM peekofLinkListStack(linkListStack*s)
{
    if(s->size==0)
    {
        printf("\nget peek failed, because linkListStack is empty!\n");
        return -1;
    }
    return s->top->var;
}
void linkListStackPush(linkListStack *s, STACK_ELEM elem)
{
    linkListStackNode *node=(linkListStackNode*)malloc(sizeof(linkListStackNode));
    node->next=s->top;
    node->var=elem;
    s->top=node;
    s->size++;
}
STACK_ELEM linkListStackPop(linkListStack *s)
{
    if(s->top==NULL)
    {
        printf("\npop failed, because linkListStack is empty!\n");
        return 1;
    }
    STACK_ELEM elem=s->top->var;
    linkListStackNode *backup=s->top;
    s->top=s->top->next;
    s->size--;
    free(backup);
    return elem;

}
