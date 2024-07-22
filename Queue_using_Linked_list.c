#include <stdio.h>
#include <stdlib.h>
 struct node {
 	int data;
 	struct node* next;
 };
 struct node *front=NULL;
  struct node *rear=NULL;
  
  
 void enqueue(struct node **s){
 	struct node* q=(struct node*)malloc(sizeof(struct node));
 	int value;
 	if ((*s)==NULL){
 		printf("Queue overflow\n");
	 }
	 else {
	 	printf("Enter the value you want to insert into the queue:\n");
	 	scanf("%d",&value);
	 	q->data=value;
	 	q->next=NULL;
	 }
	 if (front==NULL){
	 	front=rear=q;
	 }
	 else {
	 	rear->next=q;
	 	rear=q;
	 }
 }
 
  void dequeue(){
 	struct node *p=front;
 	int value;
 	if (front==NULL){
 		printf("Empty queue\n");
	 }
	 else {
	 	front=front->next;
	 	printf("The dequeued element from the list is %d\n",p->data);
	 	free(p);

 }}
 
 void show(){
 	struct node *ptr=front;
while (ptr!=NULL){
 		printf("%d ",ptr->data);
 		ptr=ptr->next;
	 }
	 printf("\n");
 }
int main(){
	int input;
	struct node * s=(struct node*)malloc(sizeof(struct node));
	do {
	printf("Enter the operations you want to perform\n1.Enqueue the element to the list\n2.Dequeue the element from the list.\n3.Display the elements\n4.Exit\n");
	scanf("%d",&input);	
		switch (input){
		case 1:
				enqueue(&s);
				break;
		case 2:
				dequeue(&s);
				break;
		case 3:
				show(s);
				break;
	}
	}while(input!=4);
	
	return 0;
}