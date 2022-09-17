#include<stdio.h>
int top=-1;
int max=100;
int stack[100];
void push(int c);
void pop();
void convertToBinary(int n);
int main(){

convertToBinary(25);

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

void convertToBinary(int n){
    int rem;
    while(n>0){
        rem = n%2;
        n/=2;
       // printf("%d %d \n",rem,n);
        push(rem);
    }
    while(top>-1){
        pop();
    }


}

void pop(){
  if(top<=-1)
    {
        printf("Stack underflow\n");
        return;
    }
      
    printf("%d ",stack[top]);
  top--;

}


