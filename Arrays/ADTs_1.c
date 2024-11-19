#include <stdio.h> 

#define max_size 20 

int i; 

void create (int a[],int size){ 

for (i=0;i<size;i++){ 

printf("Enter the element at %d index: ",i); 

scanf("%d",&a[i]); 

}  } 

void insertion(int a[],int *size, int ele, int ind) 

{   if (ind >*size && ind<0) { 

        printf("invalid"); 

        return;   } 

  for (i=*size;i>ind;i--){ 

a[i]=a[i-1];} 

a[ind]=ele; 

(*size)++;} 

void deletion(int arr[],int *size,int index){ 

if (index>*size && index<0){ 

printf("invalid"); 

return;} 

for (i=index;i<*size-1;i++){ 

arr[i]=arr[i+1];} 

(*size)--;} 

void searching(int a[],int ele, int size){ 

for (i=0;i<size;i++){ 

if (a[i]==ele){ 

printf("The %d is at %d index\n",ele,i);}}} 

void display(int a[],int size){ 

for (i=0;i<size;i++){ 

printf(" %d",a[i]);} 

printf("\n");} 

int main(){ 

int input,ele,ind; 

int arr[max_size]; 

int size; 

do { 

printf("==============Menu===================\n  1.Create an array\n  2.Insert an element to the array\n  3.Delete the element from the array\n  4.Search an element in the array\n  5.Display the element of the array\n  6.Exit\n"); 

scanf("%d",&input); 

switch (input){ 

case 1: 

printf("enter the size of array you want to create: "); 

scanf("%d",&size); 

create(arr,size); 

break; 

case 2: 

printf("enter the element you want to insert and the respective index:"); 

scanf("%d\n%d",&ele,&ind); 

insertion(arr,&size,ele,ind); 

break; 

case 3: 

printf("Enter the index of the element you want to delete:"); 

scanf("%d",&ind); 

deletion(arr,&size,ind); 

break; 

case 4: 

printf("Enter the element you want to search: "); 

scanf("%d",&ele); 

searching(arr,ele,size); 

break; 

case 5: 

display(arr,size); 

break;}        }while (input!=6); 

return 0;} 