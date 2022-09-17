#include<stdio.h>
#include<stdlib.h>

struct Bank
{
  int accNo;
  char name[100];
  int age;
  char address[100];
  int balance;
};
void deposit(struct Bank *acc,int money);
void createAcc(struct Bank *acc){
    int cash;
    printf("Enter your name\n");
    scanf("%s",acc->name);
    printf("Enter your age\n");
    scanf("%d",&acc->age);
    printf("Enter your adress\n");
    scanf("%s",acc->address);
    printf("\n");
    srand((unsigned)clock());
    acc->accNo =  (rand() % (11000 - 10000 + 1)) + 10000;
    printf("Acc No: %d created succesfully\n",acc->accNo);
    printf("Deposit a minimum amount of 500 \n");
    do{
    printf("Enter amount to be deposited \n");
        scanf("%d",&cash);
        if(cash<=500){
        printf("Enter a miniumum amount of 500.Try Again\n");
        
        
        }
        else
        deposit(&acc,cash);
    }while(cash<=500);
}
 void displayInfo(struct Bank *acc) {

    printf("Account Holder Name: %s \n",acc->name);
    printf("Account No: %d \n",acc->accNo);
    printf("Age: %d  \n",acc->age);
    printf("Balance: %d \n",acc->balance);

  }

void listAccs(struct Bank accs[], int n){
int i;
for ( i = 0; i < n; i++) {
  printf("\n\n\n");
displayInfo(&accs[i]);
  printf("\n\n\n");
}


}

void deposit(struct Bank *acc,int money) {
  
    
    acc->balance += money;
   printf("Amount deposited succesfully: %d\n",money);
    printf("Total Balance: %d \n",acc->balance);
  }

  void widthdraw(struct Bank *acc) {
    int money;
    printf("Enter amount to be widthdrawn\n");
    scanf("%d",&money);
    if ((acc->balance - money) < 500) {
      printf("Insufficient balance. Miniumum balance :500 \n");
      displayInfo(&acc);
      return;
    }
    acc->balance -= money;
    printf("Amount widthdrawn succesfully: %d\n",money);
    printf("Total Balance: %d \n",acc->balance);
  }

  void transaction(struct Bank acc){ 
    int choice;
  int cash;
    do {
      printf("Press 1 to deposit money\n");
      printf("Press 2 to widthdraw money\n");
      

      printf("Press 3 to cancel\n");

     scanf("%d",&choice);
      switch(choice){

        case 1: 
        printf("Enter amount to be deposited \n");
        scanf("%d",&cash);
        deposit(&acc,cash);
        break;
        case 2:
        widthdraw(&acc);
        break;

        case 3:
        return;
        default:
        printf("Enter a valid choice\n");

      }
      
     
        
    } while (choice != 3);

  }

void login(struct Bank accs[], int n) {
  int tempNo;
  int choice;
  int i;
  printf("Enter your account number \n");
  scanf("%d",&tempNo);
  for ( i = 0; i < n; i++) {
    printf("acc no: %d \n",accs[i].accNo);
    if (accs[i].accNo == tempNo) {
      printf("account found \n");
      displayInfo(&accs[i]);
      // accs[i].transaction();
      do{
      printf("Press 1 to perform a transaction\n");
      printf("Press 2 to exit.\n");
      scanf("%d",&choice);
      if(choice==1)
        transaction(accs[i]);

      else if(choice==2)
          return;

        
      }while(choice!=3);
      
      return;
    }

    printf("Account not found.Please enter valid account number\n");
  }

}


int main(){

struct Bank accs[100];
  int nos = 0;
int choice;
int i;
  do {
  printf("1.Create account\n");
  printf("2.List all accounts\n");
  printf("3.Find account\n");
  // printf("4.Make a transaction"\n");
  printf("4.Exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
  	case 1:
  	createAcc(&accs[nos]);
    nos++;
   	break;
  	case 2:
  	listAccs(accs,nos);
  	break;
  	case 3:
  	login(accs,nos);
  	break;
  	// case 4:
  	// transaction();
  	default:
    printf("Please enter a valid choice\n");
  	
  
  }
  } while (choice != 4);
  
 

}