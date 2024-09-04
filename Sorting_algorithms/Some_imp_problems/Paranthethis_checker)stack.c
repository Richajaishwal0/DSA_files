#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct  node {
	int  data;
	struct node * next;
};

void push(struct node **top, int data){
	struct node * newnode=(struct node * )malloc(sizeof(struct node));
	if (newnode==NULL){
		printf("Stack overflow");
		return ;
	}
	else {
		newnode->data=data;
		newnode->next=(*top);
		(*top)=newnode;
	}
}
int  pop(struct node ** top){
	struct node * ptr=(*top);
	char res;
	if ((*top)==NULL){
		printf("Stack Underflow");
		return 0;
		
	}
	else{
		res=ptr->data;
		(*top)=(*top)->next;
		free(ptr);
		return res;
	}
}

int isMatchingpair(char char1, char char2){
	if (char1=='(' && char2==')'){
		return 1;
	}
	else if (char1=='{' && char2=='}'){
		return 1;
	}
	else if (char1=='[' && char2==']'){
		return 1;
	}
	else {
		return 0;
	}
}
int isBalanced(char str[]){
int i=0;
struct node * stack=NULL;
while (str[i]){
	if (str[i]=='(' || str[i]=='{' || str[i]=='['){
		push(&stack, str[i]);
	}
	if (str[i]=='}' || str[i]==')' || str[i]==']'){
		if (stack==NULL){
			return 0;
		}
		else if (!isMatchingpair(pop(&stack),str[i])){
			return 0;
		}
	}
	i++;
}	
	if (stack ==NULL){
		return 1;
	}
	else{
			return 0;
	}

}
int main(){
	char str[100]="{()}[]";
//	printf("Enter the string: ");
//	scanf("%s",&str);
	if (isBalanced(str)){
		printf("Balanced");
	}
	else {
		printf("Not Balanced");
	}
	return 0;
}