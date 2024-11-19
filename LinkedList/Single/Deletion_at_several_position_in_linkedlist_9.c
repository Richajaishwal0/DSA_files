	#include <stdio.h>
	#include <stdlib.h>
	
	 struct node {
	 	int data;
	 	struct node* next;
	 };
	 int isEmpty(struct node**head){
		 	if ((*head)==NULL)
			 {
				printf("The linkedlist is empty\n");
				return 1;
			 }
			return 0;
	 }
	 
	void deleteFromBeg(struct node** head){
		if (!isEmpty(head))
		{
			struct node *s =(*head);
			(*head)=(*head)->next;
			printf(" The element removed from the list is %d\n",s->data);
			free(s);
		}
	}
	void deleteInBetween(struct node **head){
		struct node* ptr=(*head);
		struct node *q;
		int i=0,index;
		if (!isEmpty(head))
		{
	
				printf("Enter the index of the node you want to delete:\n");
				scanf("%d",&index);
				while (i<index-1){
					ptr=  ptr->next;
					q=ptr->next;
					i++;
				}
				ptr->next=q->next;
				printf("The element removed from the list is %d\n",q->data);
				free(q);
		
	}  
	}
	
	void deleteLastNode(struct node **head){
		struct node* ptr=(*head);
		struct node*q;
		if (!isEmpty(head))
		{
				
					do
					{	
						ptr=ptr->next;
						q=ptr->next;
					}
					while (q->next!=NULL);
				
				ptr->next=q->next;
				printf("The element removed from the list is %d\n",q->data);
				free(q);
		}
	}
		void deleteGivenValue(struct node **head){
			int value;
			struct node*p=(*head);
			struct node*q=p->next;
			
			if (!isEmpty(head)){
			
						 printf("Enter the value of the node you want to delete:\n");
						 scanf("%d",&value);
						 	if (p->data==value){
						 	printf("The element removed from the list is %d\n",p->data);
							*head=p->next;
						
						}
							while (q->data!=value &&q->next!=NULL){
							p=p->next;
							q=p->next;
						
						}  
						 if (q->data==value){
						p->next=q->next;
							printf("The element removed from the list is %d\n",q->data);
						free(q);
						}
						else {
							printf("The element is not present in the list");
						}
	}	}
	 void printLinkedList(struct node *head){
	 	struct node* ptr=head;
	 	printf("The element in the list is :");
	 	while (ptr!=NULL){
	 		printf(" %d ",ptr->data);
	 		ptr=ptr->next;
	 	
		 }
		 printf("\n");
	 }
	
	int main(){
	int input;
	struct node* head=(struct node* )malloc(sizeof(struct node));
	struct node* second=(struct node* )malloc(sizeof(struct node));
	struct node*third=(struct node* )malloc(sizeof(struct node));
	struct node* fourth=(struct node* )malloc(sizeof(struct node));
	struct node* fifth=(struct node* )malloc(sizeof(struct node));
	 head->data=20;
	 head->next=second;
	 
	 second->data=3;
	 second->next=third;
	 
	 third->data=4;
	 third->next=fourth;
	 
	 fourth->data=5;
	 fourth->next=fifth;
	 
	 fifth->data=7;
	 fifth->next=NULL;	
	
	 printf("The elements in the list are 20 3 4 5 7\n");
	do
	{
	printf("===List of Operations==\n1.Delete a node  from the beginning\n2.Delete a node in between\n3.Delete the last node\n4.Delete a node with the given value\n5.Print\n6.Exit\n");	
	scanf("%d",&input);
	
	switch (input)
		{
		case 1:
		deleteFromBeg(&head);
			break;
		case 2:
			deleteInBetween(&head);
			break;
		case 3:
			deleteLastNode(&head);
			break;
		case 4:
			deleteGivenValue(&head);
			break;
		case 5:
			printLinkedList(head);
			break;
		}
	}
	while (input!=6);	
	}