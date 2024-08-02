#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node*pre;
	struct node*next;
};
struct node * head;
void insertion_beginning(); 
void insertion_last(); 
void insertion_specified(); 
void  deletion_beginning(); 
 void deletion_last();  
 void deletion_specified();    `
 void display();            
int main(){
	
int choice =0;  
    while(choice != 8)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning();  
            break;  
            case 2:  
            insertion_last();  
            break;  
            case 3:  
            insertion_specified();  
            break;  
            case 4:  
            deletion_beginning();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specified();  
            break;  
            case 7:  
            display();  
            break;   
            default:  
            printf("Please enter valid choice..");  
        }
		  
    }
    return 0;
	}  
    
  void  insertion_beginning(){
    	int item;
    	struct node* neww=(struct node*)malloc (sizeof(struct node));
    	if (neww==NULL){
    		printf("\nOverflow\n");
		}
		printf("Enter the value");
		scanf("%d",&item);
		if (head==NULL){
			neww->pre=NULL;
			neww->next=NULL;
			neww->data=item;
			head=neww;	
		}
		else {
			neww->pre=NULL;
			neww->next=head;
			neww->data=item;
			head=neww;
		}
	}
    
   void  insertion_last(){
    	int item;
    	struct node * temp=head;
    	struct node* neww=(struct node*)malloc (sizeof(struct node));
    	if (neww==NULL){
    		printf("\nOverflow\n");
		}
		printf("Enter the value");
		scanf("%d",&item);
		if (head==NULL){
			neww->pre=NULL;
			neww->next=NULL;
			neww->data=item;
			head=neww;	
		}
		else {
			while (temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=neww;
			neww->pre=temp;
			neww->next=NULL;
			neww->data=item;
		
		}
	}
    
    void  insertion_specified(){
    	int loc,value,i;
    	struct node *temp=head;
    struct node* neww=(struct node *)malloc (sizeof(struct node));
    	if (neww==NULL){
    		printf("\nOverflow\n");
		}
		printf("Enter the location(index):\n");
		scanf("%d",&loc);
			printf("Enter the value:\n");
		scanf("%d",&value);
		 if (loc == 0) { 
        neww->data = value;
        neww->next = head;
        neww->pre = NULL;
        if (head != NULL) {
            head->pre = neww;
        }
        head = neww;
        return;
    }
		
		for (i=0;i<loc-1;i++){
		temp=temp->next;
		
			if (temp==NULL){
			printf("Enter the valid location.\n");
			free(neww);
			return;
	}}
		 if (temp->next == NULL) {
        printf("Enter a valid location.\n");
        free(neww);
        return;
			}
	
		else{
			neww->data=value;
			neww->next=temp->next;
			neww->pre=temp;
			temp->next->pre=neww;
			temp->next=neww;
		}
	}
	void deletion_beginning(){
		struct node *ptr;
		if (head==NULL){
			printf("\nUnderflow\n");
			
	}
	else if (head->next==NULL){
	head=NULL;
	free(head);	
	}
	else {
		ptr=head;
		head=head->next;
		head->pre=NULL;
		free(ptr);
		printf("Node deleted\n");	
	}
}

void deletion_last()  
{  int i,loc;
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
        return ;
    }
	 else if(head->next == NULL)  
    {  
        
		ptr=head;
		head = NULL;   
        free(ptr);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
		ptr=head;
    while (ptr->next!=NULL)
	{
    ptr=ptr->next;
    
		}
    ptr->pre->next=NULL;
    free(ptr);
		}
		
    }  
  
void deletion_specified(){
	struct node * ptr,* temp;
	ptr=head;
	int index,i;
	 if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    } 
	else {
		printf("Enter the index:");
		scanf("%d",&index);
		while (i<index-1){
			ptr=ptr->next;
			temp=ptr->next;
			i++;
		}
		
		ptr->next=temp->next;
		temp->next->pre=ptr;
		free(temp);
		printf("\n Node deleted\n");
		
	}   
	
}
	
	void display(){
	struct node * temp=head;
	while (temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
    
}
    
 
