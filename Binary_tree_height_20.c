#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node* right;
};
struct node * createNode(int data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	
}
int height(struct node * root){
	int lh,rh;
	if (root==NULL){
		return 0;
	}
	lh=height(root->left);
	rh=height(root->right);
	if (lh>rh){
	return lh+1;
	}
	else {
		return rh+1;
	}

}
 int main(){
 	struct node * root;
 	struct node * p1;
 	struct node *p2;
 	struct node * p3;
 	struct node *p4;
 	root=createNode(3);
 	p1=createNode(2);
 	p2=createNode(5);
 	p3=createNode(1);
 	p4=createNode(7);
 	root->left=p1;
 	root->right=p2;
 	p1->left=p3;
 	p2->right=p4;
 	printf("%d",height(root));
	return 0;
	 }