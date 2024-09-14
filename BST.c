//check if the given binary tree is BST or not
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node *right;
};

struct node * createNode(int data){
	struct node* newnode=(struct node * )malloc(sizeof(struct node));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
	}

int isBST(struct node * root){
	static struct node * prev=NULL;
	if (root!=NULL){
		if (!isBST(root->left)){
			return 0;	
		}
		if (prev!=NULL && root->data<=prev->data){
			return 0;
		}
		prev=root;
		return isBST(root->right);
	}
	return 1;
}
int main(){
	struct node * root;
	struct node * p1;
	struct node * p2;
	struct node * p3;
	struct node * p4;
	root=createNode(5);
	p1=createNode(3);
	p2=createNode(2);
	p3=createNode(1);
	p4=createNode(4);
	root->left=p1;
	root->right=p2;
	p1->left=p3;
	p1->right=p4;
	int result=isBST(root);
	printf("%d",result);
	return 0;
}