	#include <stdio.h>
	#include <stdlib.h>
	struct node {
		int data;
		struct node* next;
	};
	 int isEmpty(struct node **top){
	 	if ((*top)==NULL){
	 		printf("The stack is empty\n\n");
	 		return 1;
		 }
		 return 0;
	 }
	
	
	 int isFull(struct node **top){
	 	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	 	if (ptr==NULL){
	 		printf("The stack is full\n\n");
	 		return 1;
		 }
		 return 0;
	 }
	
	void push (struct node **top){
	
		int value;
		if (!isFull(top)){
			printf("Enter the value you want to push inside the node:\n");
			scanf("%d",&value);
				struct node *p=(struct node*)malloc(sizeof(struct node));
				p->data=value;
				p->next=*top;
				*top=p;
				printf("%d has been pushed succesfully\n\n",value);
		}
	}
	
	void pop(struct node **top){
		if(!isEmpty(top)){
			struct node *s=*top;
			(*top)=(*top)->next;
			printf("The poped value is %d\n\n",s->data);
			free(s);
		}
	}
	void peek(struct node  **top){
		if (!isEmpty(top)){
		printf("The peek value is %d.\n\n",(*top)->data);
	}
	}
	
	  void 	show(struct node* s){
	  	if (!isEmpty(s){ 
	  	struct node* st=s;
		while (st!=NULL){
			printf("%d ",st->data);
			st=st->next;
		}}
		printf("\n");
	}
	int main(){
		int input;
		struct node * top=NULL;
		do {
		
		printf("Perform the following operations\n1.Push element inside the stack\n2.Pop the element from the stack\n3.display the element\n4.Peek of the node\n5.Exit\n=====Enter the operation you want to perform=====\n");
		scanf("%d",&input);
			switch(input){
			case 1:
				push(&top);
				break;
			case 2:
				pop(&top);
				break;
			case 4:
				peek(&top);
				break;
			case 3:
				show(top);
				break;	
		}
		}while (input!=5);
		
		return 0;
	}