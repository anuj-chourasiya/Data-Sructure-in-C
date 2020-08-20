#include <stdio.h>
#define CAPACITY 5

int stack[CAPACITY];
int top=-1;

int isfull(){
 if(top==CAPACITY)
 {
	 return 1;
 }
 else{
  return 0;
 }
}

int isempty()
{
   if(top==-1)
   {
   return 1;
   }
    else{
    return 0;
}
}
void push(int item){
    if(isfull())
    {
	    printf("stack is full");

    }
    else{
    top++;
    printf("top is %d",top);
    stack[top]=item;
    printf("pushed successfully %d\n",stack[top]);
    
       }

}

int pop(){
	
    if(isempty())
    {
    printf("stack is empty");
    }
    
    
    else
    {
    int item;
    item=stack[top];
    top--;
    return item;
    }	    
}
void main(){
    int choice,item,it;
    char c;
    do{
    printf("Enter 1 to push \n 2 to pop");
    scanf("%d",&choice);
    switch(choice)
    {
	    case 1:
		    
		    printf("Enter item to push");
		    scanf("%d",&item);
		    push(item);
		    break;
	   case 2:
		    it=pop();
		    printf("poped item is %d\n",it);
		    break;
           default:
		    printf("Check your choice or your eye vision");

    
    
    }
    printf("Do you want to continue ?enter y or n");
    scanf(" %c",&c);
    }while(c=='y');
}
