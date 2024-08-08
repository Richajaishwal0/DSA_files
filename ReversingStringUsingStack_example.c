#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char data;
struct stack{
	int size;
	int top;
	char name[20];
};
void push(struct stack *s,char data){
	if (s->top==s->size-1){
		printf("stack overflow\n");
		return;	
	}
	s->top++;
	s->name[s->top]=data;
	
}

char pop(struct stack *s){
	if (s->top==-1){
		printf("Stack underflow\n");
		return '\0';
	}
	data =s->name[s->top];
	s->top--;
	return data;
}

void reverse(struct stack *s,char *str){
	int length=strlen(str);
	int i,j;
	for (i=0;i<length;i++){
		push(s,str[i]);
	}

	for (j=0;j<length;j++){
		str[j]=pop(s);
	}
	printf("\n");

}
int main(){
	struct stack s;
	s.size=20;
	s.top=-1;
	char name[20];
	printf("Enter the name :");
	scanf("%20s",&(name));
	reverse(&s,name);
	printf("%s\n",name);
	return 0;
}