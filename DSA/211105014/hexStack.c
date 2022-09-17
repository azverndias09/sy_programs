#include<stdio.h>
int top=-1;
int max=100;

void push(int c);
void pop();
void ConvertToHex(char stack[],int n);
int main(){
char stack[100];
ConvertToHex(1000);

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

void ConvertToHex(char stack[],int n){
   int rem;
    while(n>0){
        rem = n%16;
        n/=16;
       // printf("%d %d \n",rem,n);
        if(rem>9){
        switch(rem){
            case 10:
            push('A');
            break;
            case 11:
            push('B');
            break;
            case 12:
            push('C');
            break;
            case 13:
            push('D');
            break;
            case 14:
            push('E');
            break;
            case 15:
            push('F');
            break;
        }
        break;
        }
       int ch= rem+'0';
        push(ch);
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
    printf("%c ",stack[top]);
  top--;

}


