#include <stdio.h>

int search(int no,int arr[],int size){
    int count=1;
   for(int i=0;i<size;i++){
       if(arr[i]==no){
        return count;
       }
       count++;
   }
}

void main(){
 int arr[]={1,4,3,7,5,9};
 int no,index,size;
 size=sizeof(arr)/sizeof(arr[0]);
 printf("size is %d",size);
 printf("enter the no to be searched from 1,3,4,5,7,9\n");
 scanf("%d",&no);
 index=search(no,arr,size);
 printf("your no. %d found at %d index",no,index);
  
}
