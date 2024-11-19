#include <stdio.h>
int size=0;
void  swap(int*a , int * b){
	int temp=*a;
	 *a=*b;
     *b=temp;
}
void heapify(int arr[], int size, int  i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if (l<size && arr[l]>arr[largest]){
		largest=l;
	}
	else if (r<size && arr[r]>arr[largest]){
		largest=r;
	}
	if (largest!=i){
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, i);
	}
}

void insert(int arr[],int newnode){
	int i;
	if (size==0){
		arr[0]=newnode;
		size++;
	}
	else {
		arr[size]=newnode;
		size++;
		for (i=size/2-1;i>=0;i--){
			heapify(arr, size,i);
		}
	}
}
void print(int arr[], int size){
	int i;
	for (i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
void del(int arr[], int num){
	int i;
	for (i=0;i<size;i++){
		if (arr[i]==num){
			break;
		}
		
	}
	swap(&arr[i],&arr[size-1]);
	size-=1;
	for (i=size/2-1;i>=0;i--){
	heapify(arr, size,i);	
	}
	
}
int main(){
	int input,num;
	int arr[10];
	do {
		printf("\nEnter the operation you want to perform in Binary heap.\n1.insert\n2.Delete\n3.Print\n4.Exit\n");
		scanf("%d",&input);
		switch (input){
			case 1:
				printf("Enter the element to insert.\n");
				scanf("%d",&num);
				insert(arr,num);
				break;
			case 2:
				printf("Enter the element to delete.\n");
				scanf("%d",&num);
				del(arr,num);
				break;
			case 3:
				print(arr,size);
				break;
			
		}
		
	}while (input!=4);
}