#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node{
	int S_N;
	char Name[30];
	int Class;
	int Rollno;
	float Science;
    float Computer;
	float English;
	float  Social;
	float total;
	float percentage;
	struct node* next;
};

int isEmpty(struct node** head){
	if ((*head)==NULL){
		printf("The list is empty");
		return 1;
	}
	return 0;
}
void storeDetails(struct node** head){
		int i,n;
		printf("Enter the number of students detail you want to insert: \n");
		scanf("%d",&n);
				for (i = 0; i < n; i++) {
						struct node* ptr=(struct node*)malloc(sizeof(struct node));
						if (ptr==NULL){
						printf("Storage Full\n");
						return;
						}
							printf("Enter the details of students\n");
							printf("1. Name: ");
						    scanf("%20s", &ptr->Name);
						    
						    printf("2. Class: ");
						    scanf("%d", &ptr->Class);
						
						    printf("3. Rollno: ");
						    scanf("%d", &ptr->Rollno);
						
						    printf("4. Science: ");
						    scanf("%f", &ptr->Science);
						
						    printf("5. Computer: ");
						    scanf("%f", &ptr->Computer);
						
						    printf("6. English: ");
						    scanf("%f", &ptr->English);
					
						    printf("7. Social: ");
						    scanf("%f", &ptr->Social);
							ptr->next=NULL;
    					
    					
					    if ((*head)==NULL)
						{
					    	*head=ptr;
						}
				else {
					
					struct node* p=(*head);
						while(p->next!=NULL){
							p=p->next;
					}
			
			p->next=ptr;
			ptr->next=NULL;
				
			}
			
		}
}

void transversal(struct node* head){
	if (!isEmpty(&head)){
	struct node* ptr=head;
printf("%s %-20s %-5s %-5s %-8s %-10s %-7s %-7s %-10s %-12s\n","S_NO"
       "Name", "Class", "Rollno", "Science", "Computer", "English", "Social","Total", "Percentage");
      int i=1;
while (ptr != NULL) {
	ptr->total=ptr->Computer+ptr->English+ptr->Social+ptr->Science;
	ptr->percentage=ptr->total/400 *100;
    printf(" %d %-20s %-5d %-5d %-8.2f %-10.2f %-7.2f %-7.2f %-10.2f %-12.2f\n",
    	i++,
           ptr->Name, 
           ptr->Class, 
           ptr->Rollno, 
           ptr->Science, 
           ptr->Computer, 
           ptr->English, 
           ptr->Social,
		    ptr->total, 
           ptr->percentage);
    ptr = ptr->next;
    
}

	}

else {
	isEmpty(&head);
}}

void beg(struct node** head){
//	struct node*ptr=(*head);
	struct node*s=(struct node*)malloc(sizeof(struct node));
		printf("1. Name: ");
						    scanf("%20s", &s->Name);
						    
						    printf("2. Class: ");
						    scanf("%d", &s->Class);
						
						    printf("3. Rollno: ");
						    scanf("%d", &s->Rollno);
						
						    printf("4. Science: ");
						    scanf("%f", &s->Science);
						
						    printf("5. Computer: ");
						    scanf("%f", &s->Computer);
						
						    printf("6. English: ");
						    scanf("%f", &s->English);
					
						    printf("7. Social: ");
						    scanf("%f", &s->Social);
	s->next=(*head);
(*head)=s;
	
	
}

void last(struct node** head){
	struct node*ptr=(*head);
	struct node*s=(struct node*)malloc(sizeof(struct node));
	while (ptr->next!=NULL){
		ptr=ptr->next;
	}
	
							printf("1. Name: ");
						    scanf("%20s", &s->Name);
						    
						    printf("2. Class: ");
						    scanf("%d", &s->Class);
						
						    printf("3. Rollno: ");
						    scanf("%d", &s->Rollno);
						
						    printf("4. Science: ");
						    scanf("%f", &s->Science);
						
						    printf("5. Computer: ");
						    scanf("%f", &s->Computer);
						
						    printf("6. English: ");
						    scanf("%f", &s->English);
					
						    printf("7. Social: ");
						    scanf("%f", &s->Social);
	s->next=ptr->next;
	ptr->next=s;	
}

void mid(struct node ** head){
	struct node* ptr=(*head);
	struct node* q=(*head)->next;
	struct node* s=(struct node*)malloc(sizeof(struct node));
	if (s == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
	int NO;
	printf("Enter the rollno before which  you want to enter the data:\n ");
	scanf("%d",&NO);
	while ( ptr!=NULL && q->Rollno!=NO){
		ptr=ptr->next;
		q=q->next;
	}
	 if (ptr == NULL) {
        printf("Roll number %d not found in the list.\n", NO);
        free(s); 
        return;
    }
        printf("Enter the details for the new node:\n");
		printf("1. Name: ");
						    scanf("%20s", &s->Name);
						    
						    printf("2. Class: ");
						    scanf("%d", &s->Class);
						
						    printf("3. Rollno: ");
						    scanf("%d", &s->Rollno);
						
						    printf("4. Science: ");
						    scanf("%f", &s->Science);
						
						    printf("5. Computer: ");
						    scanf("%f", &s->Computer);
						
						    printf("6. English: ");
						    scanf("%f", &s->English);
					
						    printf("7. Social: ");
						    scanf("%f", &s->Social);
	s->next=ptr->next;
	ptr->next=s;
}

void insert(struct node** head){
	int p;
	printf("Enter the positions\n1.Starting\n2.End\n3.Given_position\n");
	scanf("%d",&p);
		switch (p){
		case 1:
			beg(head);
			break;
		case 2:
		  last(head);
			break;
			
		case 3:
			mid(head);
			break;	
}
}

void beg_d(struct node** head){
	struct node*ptr=(*head);
	(*head)=(*head)->next;
	printf("Deleted Successfully.\n");
	free(ptr);
}

void mid_d(struct node** head){
	int n;
	struct node*ptr=(*head);
	struct node*q=NULL;
	printf("Enter the rollno for which you want to delete  the data:\n ");
	scanf("%d",&n);
	
	if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
     if (ptr != NULL && ptr->Rollno == n) {
        *head = ptr->next;  
        free(ptr); 
        return;
    }
        
	while ( ptr!=NULL && ptr->Rollno!=n ){
		q=ptr;
		ptr=ptr->next;
	}
	
	
	if (ptr == NULL) {
        printf("Roll number %d not found.\n", n);
        return;
    }
    
    q->next = ptr->next;
    free(ptr);
    printf("Node with roll number %d deleted.\n", n);

}

void last_d(struct node** head){
	struct node* ptr=(*head);
	struct node*q;
	while(q->next!=NULL){
		ptr=ptr->next;
		q=ptr->next;
	}
	ptr->next=NULL;
	free(q);
	 printf("Deleted. successfully\n", n);
}
void deletion(struct node**head){
	int p;
	printf("Enter the positions\n1.Starting\n2.End\n3.Given_position\n");
	scanf("%d",&p);
		switch (p){
		case 1:
			beg_d(head);
			break;
		case 2:
		  last_d(head);
			break;
			
		case 3:
			mid_d(head);
			break;	
	
}
}
int main(){
	struct node* head=NULL;
	int input;
	do{
	printf("======Student Result management System =======\n1.Enter the students details\n2.Insert the new Details\n3.Delete the existing details\n4.Display the Existing details\n5.Exit\n");
	scanf("%d",&input);	
		switch (input){
		case 1:
		storeDetails(&head);
			break;
		case 2:
		  insert(&head);
			break;
			
		case 3:
			deletion(&head);
			break;
		
		case 4:
			transversal(head);
			break;
		}
	
		}while(input!=5);
	
	
	return 0;
}