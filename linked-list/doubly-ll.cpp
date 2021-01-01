#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int item){
    struct Node *new_node= new Node();
    new_node->data=item;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}

struct Node* append(struct Node* head,int item){
    if(head==NULL){
         
         struct Node* new_node=createNode(item);
         head=new_node;
         return head;
    }
    else{
        struct Node* new_node=createNode(item);
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;

        
    }
    return head;
}

struct Node* push_front(struct Node* head,int item){
    struct Node* new_node,*temp;
    new_node=createNode(item);
    if(head==NULL){
        head=new_node;
        
    }
    else{
        temp=head;
        temp->prev=new_node;
        new_node->next=temp;
        head=new_node;
        
       
    }
    return head;
}

struct Node* insert_at_posi(struct Node * head,int item,int posi)
{
    struct Node* new_node = createNode(item);
    if(head==NULL)
    {
        head=new_node;
    }
    else{
        struct Node * temp;
        temp=head;
        int count=2;
        while(count<posi){
            temp=temp->next;
            count++;
        }
        new_node->next=temp->next;
        temp->next->prev=new_node;
        temp->next=new_node;
        new_node->prev=temp;
        
    }

    return head;
}

void printList(struct Node *n)
{
  struct Node * p;
  p=n;
  while(n!=NULL)
  {
    cout<<n->data<<endl;
    n=n->next;
    if(n!=NULL){
        p=p->next;
    }
  }
  cout<<"from backward"<<endl;
  
  while(p!=NULL)
  {
    cout<<p->data<<endl;
    p=p->prev;
  }
  
}



int main(){
    
    struct Node *head;
 
    head=append(head,10);
    head=append(head,20);
    head=append(head,30);
    head=append(head,40);
    head=push_front(head,1);
    head=push_front(head,2);
    head=push_front(head,3);
    head=insert_at_posi(head,300,4);
    
    printList(head);

    return 0;
}
