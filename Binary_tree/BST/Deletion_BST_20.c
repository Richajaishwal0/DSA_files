#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node * right;
};
void inorder(struct node * root){
	if (root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
struct node * getsucc(struct node * curr){
	curr=curr->right;
	while (curr!=NULL && curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}
struct node * createNode(int data){
	struct node * newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node* delnode(struct node * root, int x){
	if (root==NULL){
		return root;
	}
	if (x<root->data){
		root->left=delnode(root->left,x);
	}
	else if (x>root->data){
		root->right=delnode(root->right,x);
}
else {
//	if the data is equal to the root->data
	
//	if left child is not present
	if (root->left==NULL){
		struct node * temp=root->right;
		free(root);
		return temp;
	}
//	if the rightchild is not present
		if (root->right==NULL){
		struct node * temp=root->left;
		free(root);
		return temp;
	}
//	if both child are present
	struct node * succ=getsucc(root);
	root->data=succ->data;
	root->right=delnode(root->right,succ->data);

}}
int main(){
	struct node* root;
	struct node*p1;
	struct node*p2;
	struct node*p3;
	struct node*p4;
	struct node*p5;
	struct node*p6;
		struct node*p7;
	root=createNode(50);
	p1=createNode(30);
	p2=createNode(70);
	p3=createNode(20);
	p4=createNode(40);
	p5=createNode(60);
	p6=createNode(80);
	p7=createNode(75);
	root->left=p1;
	root->right=p2;
	p1->left=p3;
	p1->right=p4;
	p2->left=p5;
	p2->right=p6;
	p6->left=p7;
	int x=05;
	root=delnode(root,x);
	inorder(root);
	return 0;
}