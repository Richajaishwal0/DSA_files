#include <stdio.h>
#define size 5

int arr[size];
int top=-1;
int i,input,a;

int isEmpty(){
	if (top==-1){
		return 1;
}return 0;
}

int isFull(){
	if (top==size-1){
		return 1;
}return 0;
}

void push (){
	if (!isFull()){
		printf("Enter the element to be added to the stack: ");
		scanf("%d",&a);
		top++;
		arr[top]=a;
	}
	else {
		printf("stack overflow\n");
	}
}
void pop(){
	if (!isEmpty()){
		printf("The popped element is :",arr[top]);
		top--;
	}
	else {
		printf("Stak underflow\n");
	}
}
void show ()
{
	for (i=top;i>=0;i--){
		printf("%d\n",arr[i]);
	}
}

int main(){
	do {
	printf("You can perform the following operation on the stack:\n 1.push the element\n 2.Pop the element\n 3.show the element\n 4.Exit\n");
	scanf("%d",&input);
	switch (input){
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			show();
			break;
			
	}
}while (input!=4);
	return 0;
}