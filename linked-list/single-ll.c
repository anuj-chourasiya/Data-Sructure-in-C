#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node * next;
};

void printList(struct Node *n)
{
  while(n!=NULL)
  {
    printf("%d\n",n->data);
    n=n->next;
  }
}
struct Node *  create_node(int item)
	
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=item;
    newNode->next=NULL;
    return  newNode;
}

struct Node * append(struct Node * head,int item)
{
  struct Node *temp,*p;
   temp=create_node(item);
   temp->data=item;
   temp->next=NULL;
   if(head==NULL){
     head=temp;
   }
   else{
     p=head;
     while(p->next!=NULL)
     {
       p=p->next;
     }
     p->next=temp;

   
   }
   return head;

}

struct Node * insert_from_front(struct Node *head,int item)
{
  struct Node *temp,*p;
  temp=create_node(item);
  temp->data=item;
  if(head==NULL)
  {
   head=temp;
   temp->next=NULL;
  }
  else{
   p=head;
   head=temp;
   temp->next=p;
  }
  return head;
}

struct Node * insert_at_posi(struct Node * head,int item,int posi)
{
  struct Node *temp,*p,*q;
  int count=1;
  temp=create_node(item);
  if(head==NULL)
   {
     head=temp;
   }
  else{
    while(count!=posi){
    p=head;
    p=p->next;
    count++;
    }
    q=p->next;
    p->next=temp;
    temp->next=q;


  }
  return head;
}

struct Node * pop(struct Node * head)
{
  struct Node *p,*q;
  if(head==NULL)
  {
   printf("linked list is empty,not able to pop");

  }
  else{
   p=head;
   while(p->next!=NULL){
           q=p;
	   p=p->next;
     
   }
   q->next=NULL;
  }
  return head;
}

struct Node * pop_from_front(struct Node * head)
{
 if(head==NULL)
 {
 printf("no item available to pop");
 }
 else{
   head=head->next;
 }
 return head;
}

struct Node * pop_from_posi(struct Node * head ,int posi)
{
  struct Node *p,*q;
  int count=1;
  p=head;
  while(count!=posi)
  {
   q=p;
   p=p->next;
   count++;
  }
  q->next=q->next->next;
  return head;
}
 void main()
{
 struct Node *head;
 
 head=append(head,10);
 head=append(head,20);
 head=insert_from_front(head,30);
 head=insert_from_front(head,16);
 head=insert_at_posi(head,100,3);
 head=pop(head);
 head=pop_from_front(head);
 head=pop_from_posi(head,2);
 printList(head);
 
}
