#include  <stdlib.h>
#include <stdio.h>

struct queue
{
  int front;
  int rear;
  int size;
  int capacity;
  int *arr;
};

struct queue * create_queue(int capacity)
{
  struct queue *q=(struct queue *)malloc(sizeof(struct queue));
  q->front=0;
  
  q->capacity=capacity;
  q->rear=0;
  q->size=0;
  q->arr=(int *)malloc(capacity*sizeof(int));
  return q;
}
struct queue * enqueue(struct queue *q,int item)
{
	if(q->size >= q->capacity)
	{
	printf("sorry queue is full");
	}
	else{
	  q->arr[q->rear%q->capacity]=item;
	  q->rear++;
	  q->size++;

	
	}
	return q;
}
struct queue * dequeue(struct queue *q)
{
     if(q->front==q->rear)
     {
     printf("queue is empty");
     }
     else{
	q->front%q->capacity;
        q->front++;
	q->size--;
     }
}

void printQ(struct queue *q){
    for(int i=q->front;i<q->size+q->front;i++)
    {
	    
    printf("queue %d",q->arr[i%q->capacity]);
    }
}
void  main()
{
	struct queue *q=create_queue(5);
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
        enqueue(q,5);
        enqueue(q,200);

	dequeue(q);
	dequeue(q);
        enqueue(q,100);
	printQ(q);
}
