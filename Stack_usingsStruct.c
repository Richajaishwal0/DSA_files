#include <stdio.h>
#include <stdlib.h>
	struct stack{
		int size;
		int top;
		int *arr;
	};
	
	void push ( struct stack* ptr ){
		int value;
		if (ptr->top==ptr->size-1){
			printf("stack overflow\n");
		}
		else {
			printf("Enter the value");
			scanf("%d",&value);
			ptr->top++;
			ptr->arr[ptr->top]=value;
			
		}
		
	}
	void pop(struct stack* ptr){
		if (ptr->top==-1){
			printf("Stack underflow\n");
		}
		else {
			printf("The popped value is %d\n",ptr->arr[ptr->top]);
			ptr->top--;
		}
	}
	void peek (struct stack* ptr){
		if (ptr->top!=-1){
		printf("The peek value is %d\n",ptr->arr[ptr->top]);
	} else {
		printf("First push to get element.\n");
	}
	}
	void show (struct stack* ptr){
		int i;
		for (i=ptr->top;i>=0;i--){
			printf("%d ",ptr->arr[ptr->top]);
		}
		printf("\n");
	}
	
int main(){
	int n;
	struct stack *s= (struct stack*) malloc(sizeof(struct stack));
	s->size=20;
	s->top=-1;
	s->arr= (int*) malloc (s->size*sizeof(int));
	do {
		printf(" ***MENUS*** \n1.Push\n2.Pop\n3.Peek\n4.Display the elements of the array\n5.Exit\n");
		scanf("%d",&n);

	switch(n){
		case 1:
			push(s);
			break;
		case 2:
			pop(s);
			break;
		case 3:
			peek(s);
			break;
		case 4:
			show(s);
			break;	
	}

	}while (n!=5);
	
	return 0;
}