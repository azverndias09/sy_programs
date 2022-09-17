#include<stdio.h>
#include<stdlib.h>

struct node{

int data;

struct node *link;
};
struct node *createList(struct node *start);
struct node *addBeginning(struct node *start,int data);
struct node *addAtEnd();

void displayList(struct node *start);
void countList();

int main(){
int choice;
  struct node *start=NULL;



do{
printf("Enter your choice\n");
printf("1.Create List\n");
printf("2.Display List\n");
printf("3.Count List\n");
scanf("%d",&choice);

switch(choice)
{
	case 1:
	start=createList(start);
	
	break;
	 
	case 2:
	displayList(start);
	break;

	case 3:
	countList();
	break;
	
	default:
	printf("Enter valid choice\n");
	break;
}



}while(choice!=4);
}
struct node *createList(struct node *start){
	int n,i,d;
	struct node *data;
	data=(struct node*)malloc(sizeof(struct node));
	printf("enter number of elements to be added\n");
	scanf("%d",&n);
	//ask user to enter the first element
	start = addBeginning(start,data);
	
	

	return start;
	//printf("ptr data: %d",start->data);
}


void displayList(struct node *start){
	


//printf("ptr data in dpslay list: %d",start->data);


struct node *ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr=start;
while(ptr->link!=NULL){

printf("ptr data: %d\n",ptr->data);
printf("ptr link: %p\n",ptr->link);
ptr=ptr->link;
}


struct node *addBeginning(struct node *start,int co,int expo){
	struct node *data;
	temp=(struct node*)malloc(sizeof(struct node));
	if(start == NULL)
	start = data;
	else
	{
	data->link = start;
	start = data;
	}
	return start;
	
}

struct node *addAtEnd(struct node *start){
	struct node *temp,*data;
	temp=(struct node*)malloc(sizeof(struct node));
	data=(struct node*)malloc(sizeof(struct node));
	temp = start;
	while(temp->link!=NULL)
		temp = temp->link;

	temp->link = 
	
}
}
void countList(){};
