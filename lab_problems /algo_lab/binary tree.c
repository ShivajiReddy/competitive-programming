#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef struct node *Nodeptr;

struct node{
    int data;
    Nodeptr rchild;
    Nodeptr lchild;
};

#include "QueueofNodeptr.h"
#include "StackofNodeptr.h"


Nodeptr getnode(){
    return ((Nodeptr)malloc(sizeof(struct node)));
}

Nodeptr CreateBinaryTree(int item){
    int x;

    if (item!=-1)
    {
        Nodeptr temp = getnode();
        temp->data = item;

        printf("Enter the lchild of %d :",item);
        scanf("%d",&x);
        temp->lchild = CreateBinaryTree(x);
        printf("Enter the rchild of %d :",item);
        scanf("%d",&x);
        temp->rchild = CreateBinaryTree(x);
        return temp;
    }
    return NULL;


}

void Inorder(Nodeptr root){
    if (root){
        Inorder(root->lchild);
        printf("%d ",root->data);
        Inorder(root->rchild);
    }

}
void Preorder(Nodeptr root){
    if (root){
        printf("%d ",root->data);
        Preorder(root->lchild);
        Preorder(root->rchild);
    }

}
void Postorder(Nodeptr root){
    if (root){
        Postorder(root->lchild);
        Postorder(root->rchild);
        printf("%d ",root->data);

    }

}
void iterative_inorder(Nodeptr root)
{
    Nodeptr cur;
    int done = false;

    if(root==NULL){
        printf("Empty Tree\n");
        return;
    }
    cur=root;
    while(!done)
    {
        while(cur!=NULL)
        {
            Push(cur);
            cur=cur->lchild;
        }
        if(!IsEmptyStack())
        {
            cur=Pop();
            printf("%d ",cur->data);
            cur=cur->rchild;
        }
        else
            done = true;
    }
}


//makes use of Queue
void Levelorder(Nodeptr root){

    if (root== NULL)
    {
        printf("\nEmpty Tree\n");
        return;
    }
    InsertQ(root);
    while(!IsQEmpty()){
        Nodeptr temp= DeleteQ();
        printf("%d ", temp->data);
        if (temp->lchild) InsertQ(temp->lchild);
        if (temp->rchild) InsertQ(temp->rchild);

    }

}

void insert(Nodeptr root, char a[], int ele)
{
    int i;
    Nodeptr temp,cur;

    temp=(Nodeptr) malloc(sizeof(struct node));
    temp->data=ele;
    temp->lchild=temp->rchild=NULL;

    cur=root;
    i=0;
    while(a[i+1]!='\0')
    {
        if(a[i]=='L' || a[i]=='l')
            cur=cur->lchild;
        else
            cur=cur->rchild;
        i++;
    }
    if(a[i]=='L' || a[i]=='l')
    {
        if (cur->lchild)
            printf("subtree already exists..Invalid direction string ");
        else
            cur->lchild=temp;
    }
    else {

        if (cur->rchild)
            printf("subtree already exists..Invalid direction string ");
        else
            cur->rchild=temp;
    }

}


int Search(Nodeptr root,int ele) //uses preorder traversal
{
    static int t=0;
    if(root)
    {
     if(root->data==ele){
        t++;
        return t;
    }
    Search(root->lchild,ele);
    Search(root->rchild,ele);
    }
    return t;
}
int max(int a,int b)
{
    return (a>b)? a:b;
}
int height(Nodeptr root)
{
    int left,right;
    if(root==NULL)
        return 0;
    left=height(root->lchild);
    right=height(root->rchild);
    return 1+max(left,right);

}
int main(){

    Nodeptr root = NULL;

    int item;

    printf("Creating the tree : \n");
    scanf("%d",&item);

    root=CreateBinaryTree(item);

    printf("\nInorder Traversal : \n");
    Inorder(root);
    printf("\nPreorder Traversal : \n");
    Preorder(root);
    printf("\nPostorder Traversal : \n");
    Postorder(root);


    printf("\nLevel Order Traversal : \n");
    Levelorder(root);
    printf("\nIterative  inOrder Traversal : \n");
    iterative_inorder(root);



    printf("\nHeight of the tree = %d\n",height(root));

    printf("Enter the item to be searched: ");

    scanf("%d", &item);
    int t = Search(root, item);
    if (t==1)
        printf("the element found\n");
    else
        printf("the element not found\n");

    char direction[50];
    scanf("%s", direction);
    insert(root, direction, item);
    Inorder(root);
    return 0;

}

