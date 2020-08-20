#include <stdio.h>

int binary(int arr[],int no,int size){

    int left=0;
    int right=size-1;
    int middle=(left+right)/2;
    int found=0;

    while(left<=right){
	    printf("middle %d",middle);
    if (arr[middle]== no){
            found=1;        
	    break;
    }
    else if(arr[middle] < no){
       
	    left=middle;
       middle=(left+right)/2;
    }
    else if(arr[middle] > no){
	   
        right=middle;
	middle=(left+right)/2;
    }
    }
    if(found==1){
    return middle;
    }
    else{
     return -1;
    }
    
}

void main(){
  int n,size,num,index;
  printf("Enter the no of element ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter elements in sorted order");
  for(int i=0;i<n;i++){
	  printf("Enter %d element ",i+1);
	  scanf("%d",&arr[i]);
  }
  
  size=sizeof(arr)/sizeof(arr[0]);
  
  printf("enter element to be searched\n");
  scanf("%d",&num);
  index=binary(arr,num,size);
  if(index>=0){
   printf("Element found at %d position",index+1);
  }
  else{
  printf("better luck next time");
  }
}
