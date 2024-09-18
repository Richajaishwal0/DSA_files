#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * createNode(int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node *  search(struct node * root, int key){
    if (root==NULL || root->data==key){
            return root;
    }
    else if (key<root->data){
        search(root->left,key);
    }
    else{
        search(root->right, key );
    }
}

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
    printf(search(root,0)!=NULL?"Found\n":"Not found\n");
return 0;
}
