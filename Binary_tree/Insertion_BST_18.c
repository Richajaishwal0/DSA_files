#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node * right;
};
struct node * createNode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node*));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void inorder(struct node * root){
    if (root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}}
void insert(struct node ** root, struct node * newnode){
    if ((*root)==NULL){
        (*root)=newnode;
    }
    else {
        if (newnode->data>(*root)->data){
            if ((*root)->right==NULL){
                (*root)->right=newnode;
            }
            else{
                insert(&((*root)->right),newnode);
            }
        }
         else if (newnode->data<(*root)->data){
            if ((*root)->left==NULL){
                (*root)->left=newnode;
            }
            else{
                insert(&((*root)->left),newnode);
            }
    }
}}
int main(){
    struct node* root;
    struct node * newnode;
    int input;
    do {
        printf("\nEnter the node to be inserted.\n And 0 to quit.\n ");
        scanf("%d",&input);
        newnode=createNode(input);
        insert(&root,newnode);
        inorder(root);
    }while (input!=0);
    
    return 0;
}
