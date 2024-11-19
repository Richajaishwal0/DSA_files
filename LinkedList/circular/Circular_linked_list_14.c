#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

void beg(struct node ** head, int data){
	struct node * ptr=(*head);
	struct node * newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=data;
	if ((*head)==NULL){
		newnode->next=newnode;
		(*head)=newnode;
		
	}
	else {
		while (ptr->next!=(*head)){
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=(*head);
		(*head)=newnode;
	}
}

void end(struct node ** head, int data){
	struct node * ptr=(*head);
	struct node * newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=data;
	if ((*head)==NULL){
		newnode->next=newnode;
		(*head)=newnode;
		
	}
	else {
		while (ptr->next!=(*head)){
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=(*head);
	}
}
void ind(struct node **head,int data){
	struct node * ptr=(*head);
	struct node * newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=data;
	if ((*head)==NULL){
		newnode->next=newnode;
		
	}
	else {
		int i=0,ind;
		printf("Enter  the index in which you want to insert:\n");
		scanf("%d",&ind);
		for (i=0;i<ind-1;i++){
			ptr=ptr->next;
		}
	
		newnode->next=ptr->next;
		ptr->next=newnode;
	}
}

void display(struct node ** head){
	struct node * ptr=(*head);
	do{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while (ptr!=(*head));
	printf("\n");
}
void del_last(struct node ** head){
	struct node * ptr=(*head);
	struct node * q=ptr->next;
	if ((*head)==NULL){
		printf("The list is empty\n");
	}
		if (ptr->next==(*head)){
			free(ptr);
			(*head)=NULL;
		}
		else {
			while (q->next!=(*head)){
				ptr=ptr->next;
				q=q->next;
			}
			ptr->next=q->next;
			free(q);
			}
	}

void del_beg(struct node ** head){
	struct node * ptr=(*head);
	struct node * q=(*head)->next;
	if ((*head)==NULL){
		printf("The list is empty\n");
	}
		if (ptr->next==(*head)){
			free(ptr);
			(*head)=NULL;
		}
		else {
			while (ptr->next!=(*head)){
				ptr=ptr->next;
			}
			ptr->next=q;
			(*head)=q;
			}
	}

void del_mid(struct node ** head){
	struct node * ptr=(*head);
	struct node * q=ptr->next;
	if ((*head)==NULL){
		printf("The list is empty\n");
	}
	if (ptr->next==(*head)){
			free(ptr);
			(*head)=NULL;
		}
		
	else {
		int i,ind;
		printf("Enter the index:\n");
		scanf("%d",&ind);
		if (ind==0){
			del_beg(head);
		}
		else{
		for (i=0;i<ind-1;i++){
			ptr=ptr->next;
			q=q->next;
		}
		ptr->next=q->next;
		free(q);
	}}
}
int main(){
	struct node * head=NULL;
	int data,inputt;
	do{
	printf("\nEnter \n1.beg\n2.index.\n3.end\n4.display\n5.del_b\n6.del_mid\n7.del_end\n8.Exit\n");
	scanf("%d",&inputt);
	switch (inputt){
		case 1:
			printf("Enter the element to be inserted:\n");
			scanf("%d",&data);
			beg(&head,data);
			break;
		case 2:
			printf("Enter the element to be inserted:\n");
			scanf("%d",&data);
			ind(&head, data);
			break;
		case 3:
			printf("Enter the element to be inserted:\n");
			scanf("%d",&data);
			end(&head, data);
			break;
		case 4:
			display(&head);
			break;
		case 5:
			del_beg(&head);
			break;
		case 6:
			del_mid(&head);
			break;
		case 7:
			del_last(&head);
			break;
	}
	}while(inputt!=8);
	return 0;
}