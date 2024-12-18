#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
};

void inorder(struct node * root){
	if (root==NULL){
		return ;
	}
	else {
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
		
	}
}

struct node * newNode(int data){
	struct node* newNode=(struct node * )malloc (sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
}
int main(){
	struct node * root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	printf("The element in the tree are:\n");
	inorder(root);
	
	return 0;
}
