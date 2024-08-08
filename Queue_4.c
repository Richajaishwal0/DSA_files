#include <stdio.h>
#define size 5

int arr[size];
int n;
int front=-1;
int rear=-1;


	int isEmpty(){
		if (front==rear){
			return 1;
		}
		return 0;
	}
	
	int isFull(){
		if (rear==size-1){
			return 1;
		}
		return 0;
	}
	
	void enqueue(){
		if (isFull()){
			printf("queue overflow\n");
		}
		else {
			int value;
			printf("ENTER THE VALUE \n");
			scanf("%d",&value);
			rear++;
			arr[rear]=value;
		}
		
	}
	
	void dequeue(){
		if (isEmpty()){
			printf("queue underflow\n");
		}
		else {
			front++;
			printf("The dequeud element is %d\n",arr[front]);
		}
	}
	void show(){
		int i;
		for (i=front+1;i<=rear;i++){
			printf("%d",arr[i]);
		}
		printf("\n");
	}
	void peek(){
		printf("%d\n",arr[rear]);
	}
	
int main(){
	do {
		printf("1.Enqueue\n2.Dequeue\n3.show\n4.peek\n5.Exit\n");
		scanf("%d",&n);
		switch (n){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				show();
				break;
			case 4:
				peek();
				break;
		}
	}while (n!=5);
	return 0;
}