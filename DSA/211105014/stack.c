#include<stdio.h>
int top=-1;
int max=100;
int stack[100];
void push(int n);
void pop();

int main(){
int a;
int choice;//push pop display top , display all quit
do{
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Peek\n");
    printf("4.Display all\n");
    printf("5.Quit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter element to be pushed\n");

        scanf("%d",&a);
        push(a);
        break;
        
        case 2:
     
        pop();
        break;

        case 3:
        peek();
        break;

        case 4:
        displayAll();
        break;

        default:
        printf("Invalid input");
        
    }
}while(choice!=5);

}

void push(int n){
if(top>=max)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top]=n;


}
void peek(){
    if(top<=-1)
    {
        printf("Stack empty\n");
        return;
    }
    printf("Top element: %d",stack[top]);
}
void displayAll(){
    int i;
    if(top<=-1)
    {
        printf("Stack empty\n");
        return;
    }
    for(i=top;i>=0;i--)
    printf("%d ",stack[i]);
    printf("\n");
}
void pop(){

  if(top<=-1)
    {
        printf("Stack underflow\n");
        return;
    }
    top--;
    printf("Element popped \n");
    printf("%d \n",stack[top]);

}


