#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void  linkedListTraversal(struct Node *head){
	while (head!=NULL){
		printf("%d\n",head->data);
		head=head->next;
	}
printf("\n");
}
 struct Node* insertionInToFirstIndex(struct Node* head, int data){
 	struct Node* ptr= head;
 	struct Node * p=(struct Node*)malloc (sizeof (struct Node));
 	p->data=data;
 	p->next=ptr;
 	return p;
 }
 
  struct Node* insertionInToLastIndex(struct Node* head, int data){
 	struct Node* ptr= head;
 	struct Node* p=(struct Node*)malloc (sizeof (struct Node));
 	while (ptr->next!=NULL){
 		ptr=ptr->next;
	 }
 	ptr->next=p;
 	p->data=data;
 	p->next=NULL;
 	return head;
 }	
 	
   struct Node* insertionAfterANode(struct Node* head,struct Node* pn, int data){
 	struct Node* ptr= head;
 	struct Node* p=(struct Node*)malloc (sizeof (struct Node));
 	p->data=data;
	 p->next=pn->next;
	 pn->next=p;
	 return head;
 }	
 	
 struct Node* insertionAtTheGivenIndex(struct Node* head,int data, int index){
 	struct Node* ptr=head;
 	struct Node* p=(struct Node*)malloc (sizeof (struct Node));
 	int i=0;
 	while (i!=index-1){
 		ptr=ptr->next;
 		i++;
	 }
	 p->data=data;
	 p->next=ptr->next;
	 ptr->next=p;
	 return head;
 }

int main(){
	struct Node *head=(struct Node*)malloc (sizeof (struct Node));;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
		
		second=(struct Node*)malloc (sizeof (struct Node));
	third=(struct Node*)malloc (sizeof (struct Node));
	fourth=(struct Node*)malloc (sizeof (struct Node));
	
	head->data=3;
	head->next=second;
	
	second->data=5;
	second->next=third;
	
	third->data=7;
	third->next=fourth;
	
	fourth->data=9;
	fourth->next=NULL;
//	**
	linkedListTraversal(head);
//	**
	head=insertionInToFirstIndex(head,0);
	linkedListTraversal(head);
//	**
    head=insertionAtTheGivenIndex(head,90,2);
    linkedListTraversal(head);
//    **
 	head=insertionInToLastIndex(head,89);
    linkedListTraversal(head);
//    **
	head=insertionAfterANode(head,second,99);
	linkedListTraversal(head);
	return 0;
}