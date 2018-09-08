#include <stdio.h>
#include <stdlib.h>
 
struct node 
{
    int value;
    struct node *l;
    struct node *r;
};

typedef struct node node;

node *ptr, *root = NULL;
 

void createbinary()
{
    root = getNode(50);
    root->l = getNode(20);
    root->r = getNode(30);
    root->l->l = getNode(70);
    root->l->r = getNode(80);
    root->l->l->l = getNode(10);
    root->l->l->r = getNode(40);
    root->l->r->r = getNode(60);
}
 

node* getNode(int val)
{
    ptr = (node*)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Memory was not allocated");
        return;
    }
    ptr->value = val;
    ptr->l = NULL;
    ptr->r = NULL;
    return ptr;
}
 

int count(node *n)
{
    int c = 1;
 
    if (n == NULL)
        return 0;
    else
    {
        c += count(n->l);
        c += count(n->r);
        return c;
     }
}
 
void preorder(node *t)
{
    if (t != NULL)
    {
        printf("%d->", t->value);    
        preorder(t->l);
        preorder(t->r);
    }
 }

 int  main()
{
    int c;
 
    createbinary();
    preorder(root);
    c = count(root);
    printf("\nNumber of nodes in binary tree are:%d\n", c);
}