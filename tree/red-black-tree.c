#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node *left;
   struct node *right;
   int color;
};

struct node * createNode(int item){

    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=item;
    node->left=NULL;
    node->right=NULL;
    node->color=1;
    return node;
}

int isRed(struct node *root){
   if(root == NULL)
   {
   return 0;
   }
   else if(root->color==1)
   {
   return 1;
   }
   else{
   return 0;
   }
}
struct node * rotateLeft(struct node *root){
    struct node *temp;
    root->right->color=0;
    root->color=1;
    temp=root->right;
    root->right=temp->left;
    temp->left=root;
    

    root=temp;
    return root;
}


struct node * rotateRight(struct node *root){

    struct node *temp;
    root->left->color=0;
    root->color=1;
    temp=root->left;
    root->left=temp->right;
    temp->right=root;


    root=temp;

    return root;
}


struct node * flipColor(struct node *root){
   root->left->color=0;
   root->right->color=0;
   root->color=1;
   return root;

}


struct node * insert(struct node * root,int item){
    
	if(root == NULL)
    {
      return createNode(item);
      
    }
    else if(root->data < item)
    {
      	 root->right=insert(root->right,item);
    }
    else if(root->data > item)
    {
      root->left=insert(root->left,item);
    }
    if(isRed(root->right) && ! isRed(root->left)){
            
	    root= rotateLeft(root);
    }
    if(isRed(root->right) && isRed(root->left)){
            
	    root=flipColor(root);
    }
    if(isRed(root->left) && isRed(root->left->left))
    {
      root=rotateRight(root);
    }
    return root;
}

int inorder(struct node *root){
   if(root==NULL)
   {
   return 0;
   }
   else{
   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
   }
}

int max(int a,int b)
{
if(a>b){
return a;
}
return b;
}

int height(struct node *root)
{
   if(root==NULL)
   {
       return 0;
   }
   else{
     return max(height(root->left)+1,height(root->right)+1);
   }
}

void main
(){

int h;
struct node *root=createNode(10);
root=insert(root,20);
root=insert(root,25);
root=insert(root,30);
root=insert(root,40);
inorder(root);
h=height(root);
printf("height is %d ",h);

}
