#include  <stdio.h>
#include <stdlib.h>

struct node
{
 int data;
 struct node *left;
 struct node *right;
};

struct node * create_tree(int item)
{
  struct node *root =(struct node *)malloc(sizeof(struct node));
  root->data=item;
  root->left=NULL;
  root->right=NULL;
  return root;
}
struct node * insert(struct node * root,int item)
{
  if(root == NULL)
  {
    root=create_tree(item);
    
  }
  else{

   if(item<root->data){
     root->left=insert(root->left,item);
   }
   else if(item > root->data){
     root->right=insert(root->right,item);
   }

  }

  
  return root;
}

void inorder(struct node * root)
{
   if(root==NULL)
   {
   return;
   }
   else{
   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
   }
}

void preorder(struct node *root)
{
 if(root==NULL)
 {
 return;
 }
 printf("%d ",root->data);
 preorder(root->left);
 preorder(root->right);
}

void postorder(struct node * root)
{
 if(root==NULL)
 {
 return;
 }
 postorder(root->left);
 postorder(root->right);
 printf("%d ",root->data);
}

int max(int a,int b)
{
   if(a>b){
     return a;
    }
   else{
    return b;
}
}

int height(struct node *root)
{
   if(root == NULL)
   {
   return 0;
   }
   else{
   return max(height(root->left)+1,height(root->right)+1);
   }
}

void main()
{
  int h;
  struct node * root=create_tree(10);
  root=insert(root,20);
  root=insert(root,30);
  root=insert(root,4);
  root=insert(root,3);
  root=insert(root,5);
  h= height(root);
  printf("height is %d ",h);
  inorder(root);
  preorder(root);
 
}
