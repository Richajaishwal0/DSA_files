	#include <stdio.h>
	#include <stdlib.h>
	int n,i;
	struct circularqueue{
		int size;
		int front;
		int rear;
		int *arr;
	};
	
	int isEmpty(struct circularqueue *s){
		if (s->front==s->rear)
	{	printf("queue underflow\n");
	return 1;
	}
	return 0;
	}
	
	int isFull(struct circularqueue *s){
		if ((s->rear+1)%s->size==s->front)
	{	printf("queue overflow\n");
	return 1;
	}
	return 0;
	}
	
	void enqueue(struct circularqueue *s){
		if (!isFull(s)){
			int value=0;
			s->rear=(s->rear+1)%s->size;
			
			printf("enter the value you want to enqueue: ");
			scanf("%d",&value);
			s->arr[s->rear]=value;
		}
	}
	
	void dequeue(struct circularqueue *s){
		int a;
		if (!isEmpty(s)){
			s->front=(s->front+1)%s->size;
			a=s->arr[s->front];
			printf("The dequeud value is %d ",a);
			
		}
	}
	
	void show(struct circularqueue *s){
		    int i = (s->front + 1) % s->size;
    while (i != (s->rear + 1) % s->size) {
        printf("%d ", s->arr[i]);
        i = (i + 1) % s->size;
    }
    printf("\n");
}
	
	int main(){
		struct circularqueue s;
		s.size=5;
		s.front=0;
		s.rear=0;
		s.arr=(int *) malloc (s.size*sizeof(int));
		  do {
		  
		  	printf("Enter\n1.enqueue\n2.dequeue\n3.show\n4.Exit\n");
		  	scanf("%d",&n);
		  	switch (n){
		  		case 1:
		  			enqueue(&s);
		  			break;
		  		case 2:
		  			dequeue(&s);
		  			break;

		  		case 3:
		  			show(&s);
		  			break;
			  }
		  }
		  while (n!=4);
		
		return 0;
	}