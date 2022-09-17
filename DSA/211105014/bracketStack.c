#include<stdio.h>
int top=-1;
int max=100;
char stack[100];
void push(char c);
void pop();
char peek();
int main(){


int n;
printf("Enter number of brackets\n");
scanf("%d",&n);
checkBrack(n);
}

void checkBrack(int n){
    int i;
    char ch;
    char latest;
    for(i=0;i<n;i++){
    printf("Enter brackets\n");
    scanf("%c",&ch);
    
    switch(ch){
    case '}':
    if(peek()=='{')
    pop();
    break;
    case ')':
    if(peek()=='(')
    pop();
    break;
    case ']':
    if(peek()=='[')
    pop();
    break;

    default:
    push(ch);
    }
    }
    


}
char peek(){
   
    return stack[top];
}
void push(char c){
if(top>=max)
    {
       
        return;
    }
    top++;
    stack[top]=c;


}

void pop(){
  if(top<=-1)
    {
       
        return;
    }
    top--;
    // printf("%c \n",stack[top]);

}


