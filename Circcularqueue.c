#include<stdlib.h>
#include<stdio.h>
#define size 5
	int front=-1;
	int rear=-1;
	int circular[size];	
void Insert();
void Delete();
void display();
void Search();


int main(){
	int choice;
	while(1){
	
		printf("\n\t\tChoose Your operation\n");
	   printf("\t\t----------------------------\n");
	    printf("\t\t----------------------------\n");
		printf("\t\t1,Insert an element to queue\n");
		printf("\t\t2,Delete an element from the queue\n");
		printf("\t\t3,Search an element from the queue\n");
		printf("\t\t4,Exit\n");
		printf("\t\t Enter your choice\t");
		scanf("%d",&choice);
		switch(choice){
		case 1:
		      Insert();
			  display();
				break;
	    case 2:
	     Delete();
	    	display();
	    	break;
		case 3:
			Search();
			break;
	case 4:
		exit(0);
		break;
    default:
		printf("No more option\n");	
	    }
	}
}
void Insert(){
	int item;
	if((front == 0 && rear == size-1)||(front == rear +1)){
		printf("\n\t\t Queue Overflow");
	}
	else{
  	rear=(rear+1)%size;
	if(front==-1){
			front=0;
			rear=0;
		}
	printf("\n\t\tEnter The Element To Be Inserted =\t");
    scanf("%d",&item);
    circular[rear]=item;
}
}
void Delete(){
	int item;
	if(front==-1){
		printf("\n\t\tqueue underflow");
		}
	else{
    item=circular[front];
	}
	if(rear==front){
		front=-1;
		rear=-1;
	}
	else{

	  	front=(front+1)%size;
	}
}
void Search(){
	int i;
	int item;
	printf("\n\t\t Enter the element to search\t");
	scanf("%d",&item);
	int front_pos=front,rear_pos=rear;
		printf("\n\t\t The Queue elements\n");
	if(front==-1){
		printf("\n\t\tQueue is empty");
	}
	if(front_pos<=rear_pos){
	
		for(i=front_pos;i<=rear_pos; i++)
		if(item==circular[i])
		printf("\n\t\tThe %d element is found in position %d",item,i+1);
	}
	else{
		for(i=front_pos;i<=size-1;i++){
		if(item==circular[i])
		printf("\n\t\tThe %d element is found in position %d",item,i+1);
		}
		front_pos=0;
		for(i=front_pos;i<=rear_pos;i++){
			if(item==circular[i])
		printf("\n\t\tThe %d element is found in position %d",item,i+1);
		}
	}
	
}
void display(){
	int i;
	int front_pos=front,rear_pos=rear;
		printf("\n\t\t The Queue elements\n");
	if(front==-1){
		printf("\n\t\tQueue is empty");
	}
	if(front_pos<=rear_pos){
	
		for(i=front_pos;i<=rear_pos; i++)
		printf ("\n\t\t%d",circular[i]);
	}
	else{
		while(front_pos<=size-1){
			printf ("\n\t\t%d",circular[front_pos]);
			front_pos++;
		}
		front_pos=0;
		while(front_pos<=rear_pos){
				printf ("\n\t\t%d",circular[front_pos]);
			front_pos++;
		}
	}
	
}

