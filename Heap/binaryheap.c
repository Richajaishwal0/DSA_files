#include <stdio.h>
#include <stdlib.h>
int size=0;
 void swap(int *a, int *b){
 	int temp=*a;
 	*a=*b;
 	*b=temp;
 }
 void heapify(int arr[],int size, int i){
 	if (size==1){
 		printf("There is single element in the heap.\n");
	 }
	 else {
	 	int largest=i;
	 	int l=2*i+1;
	 	int r=2*i+2;
	 	if (l<size && arr[l]>arr[largest]){
	 		largest=l;
		 }
		if(r<size && arr[r]>arr[largest]){
		 	largest=r;
		 }
		 if (largest!=i){
		 	swap(&arr[i],&arr[largest]);
		 	heapify(arr,size,largest);
		 }
		 
	 }
 }
 
void insert(int arr[],int newnum){
	if (size==0){
		arr[0]=newnum;
		size++;
	}
	else{
		arr[size]=newnum;
		size++;
		for(int i=size/2-1;i>=0;i--){
			heapify(arr,size,i);
		}
	}
}

void deletee(int arr[],int  num){
	int i;
	for (i=0;i<size;i++){
		if (arr[i]==num){
			break;
		}
	}
	swap(&arr[i],&arr[size-1]);
	size-=1;
	for (i=size/2-1;i>=0;i--){
		heapify(arr,size,i);
	}
}
void print(int array[],int size){
	int i;
	for (i=0;i<size;i++){
		printf("%d\n",array[i]);
		
	}
}
int main(){
	int arr[10];
	insert(arr,1);
	insert(arr,9);
	insert(arr,4);
	insert(arr,7);
	insert(arr,3);
	insert(arr,2);
	insert(arr,5);
	print(arr,size);
	printf("\n");
	deletee(arr,1);
	print(arr,size);
	return 0;
}