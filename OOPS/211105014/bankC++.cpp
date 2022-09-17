#include<iostream>

using namespace std;
#include<cstdlib>
#include<time.h>

class Bank {
  public:
    int accNo;
  char name[100];
  int age;
  char address[100];
  int balance;

  void createAcc() {

    cout << "Enter your name " << endl;
    cin >> name;
    cout << "Enter your age " << endl;
    cin >> age;
    cout << "Enter your adress" << endl;
    cin >> address;
    srand(time(0));
    accNo = rand();
    cout << "Acc No: " << accNo << endl;
  }

  void displayInfo() {

    cout << "Account Holder Name: " << name << endl;
    cout << "Account No:: " << accNo << endl;
    cout << "Age: " << age << endl;
    cout << "Balance: " << balance << endl;

  }

  void deposit() {
    int money;
    cout << "Enter amount to be deposited" << endl;
    cin >> money;
    balance += money;
    cout<<"Amount deposited succesfully: "<<money<<endl;
    displayInfo();
  }

  void widthdraw() {
    int money;
    cout << "Enter amount to be widthdrawn" << endl;
    cin >> money;
    if ((balance - money) < 500) {
      cout << "Insufficient balance. Miniumum balance :500 " << endl;
      displayInfo();
      return;
    }
    balance -= money;
    displayInfo();
  }
	

  void transaction() {
  
    int choice;

    do {
      cout << "Press 1 to deposit money" << endl;
      cout << "Press 2 to widthdraw money" << endl;
      

      cout << "Press 3 to cancel" << endl;

      cin >> choice;
      switch(choice){

        case 1: 
        deposit();
        break;
        case 2:
        widthdraw();
        break;

        case 3:
        return;
        default:
        cout << "Enter a valid choice" << endl;
      }
      
     
        
    } while (choice != 3);

  }

};
void login(Bank accs[], int n) {
  int tempNo;
  int choice;
  cout << "Enter your account number" << endl;
  cin >> tempNo;
  for (int i = 0; i < n; i++) {
    if (accs[i].accNo == tempNo) {
      accs[i].displayInfo();
      // accs[i].transaction();
      do{
      cout<<"Press 1 to perform a transaction"<<endl;
      cout<<"Press 2 to exit."<<endl;
      cin>>choice;
      if(choice==1)
        accs[i].transaction();

      else if(choice==2)
          return;

        
      }while(choice!=3);
      
      return;
    }

    cout << "Account not found.Please enter valid account number" << endl;
  }

}

void listAccs(Bank accs[], int n){

for (int i = 0; i < n; i++) {
  cout<<endl<<endl;
  accs[i].displayInfo();
  cout<<endl<<endl;
}


}

int main() {
  //cout<<"hello world"<<endl;
  Bank accs[100];
  int nos = 0;
int choice;
  do {
  cout<<"1.Create account"<<endl;
  cout<<"2.List all accounts"<<endl;
  cout<<"3.Find account"<<endl;
  // cout<<"4.Make a transaction"<<endl;
  cout<<"4.Exit"<<endl;
  cin >> choice;
  switch(choice)
  {
  	case 1:
  	accs[nos].createAcc();
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
  	break;
  	
  
  }
  } while (choice != 5);
  
 


}
