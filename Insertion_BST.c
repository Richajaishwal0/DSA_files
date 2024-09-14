#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};
void insert(struct node ** root, struct node * newnode){
	struct node * ptr=(*root);
	if ((*root)==NULL){
		*root=newnode;
	}
	else{
		if (newnode->data<ptr->data){
			if (ptr->left==NULL){
				ptr->left=newnode;
			}
			else{
				insert(&(ptr->left),newnode);
			}
		}
			else if  (newnode->data>ptr->data){
			if (ptr->right==NULL){
				ptr->right=newnode;
			}
			else{
				insert(&(ptr->right),newnode);
			}
		}
	}
}

struct node * createNode(int data){
	struct node* newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
void inorderTraversal(struct node * root){
	if (root!=NULL){
		inorderTraversal(root->left);
		printf("%d ",root->data);
		inorderTraversal(root->right);
	}
}

int main(){
	int input,data;
	struct node*root=NULL;
	struct node *neww;
	
	do{
		printf("\nEnter the choice\n1.Insert\n2.Display\n");
		scanf("%d",&input);
	switch (input){
		case 1:
			printf("Enter the element you want to insert:\n");
			scanf("%d",&data);
			neww=createNode(data);
			insert(&root,neww);
			break;
		case 2:
		   inorderTraversal(root);
		   break;
	}
	}while(input!=3);
}
//https://cse.poriyaan.in/topic/binary-search-tree-adt-50535/