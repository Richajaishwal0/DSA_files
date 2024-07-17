#include <stdio.h>

#include <stdlib.h>

	struct stack {
		int size ;
		int f;
		int r;
		int *arr;
	};
	
int isEmpty(struct stack *s){
		if (s->f==s->r){
			return 1;
		}
		return 0;
		
	}
int isFull(struct stack *s){
		if (s->r==s->size-1){
			return 1;
		}
		return 0;
		
	}
	void enqueue(struct stack *s){
		if (!isFull(s)){
			s->r++;
			int a;
				printf("Enter the value ");
				scanf("%d",&a);
				s->arr[s->r]=a;
		printf("The enqueud element is %d\n",s->arr[s->r]);	
		}
		else {
			printf("Stack overflow.\n");
		}
	}
		void dequeue(struct stack *s){
		if (!isEmpty(s)){
			s->f++;
		printf("The dequeude element is %d\n",s->arr[s->f]);	
		}
		else {
			printf("Stack underflow.\n");
		}
	}
	void show(struct stack *s){
		int i;
		for (i=s->f+1;i<=s->r;i++){
			printf("%d",s->arr[i]);
		}
		printf("\n");
	}
	void peek(struct stack *s){
		printf("%d",s->arr[s->r]);
	}
int main(){
struct stack s;
s.size=10;
s.f=-1;
s.r=-1;
int n;
s.arr= (int*)malloc (s.size* sizeof (int));
 do {
 	printf("1.Enqueue\n2.Dequeue\n3.peek\n4.Display\n");
    scanf("%d",&n);
	switch (n){
		case 1:
				enqueue(&s);
				break;
		case 2:
				dequeue(&s);
				break;
		case 3:
					peek(&s);
					break;
		case 4:
					show(&s);
					break;
	}
}while (n!=6);	
	return 0;
}