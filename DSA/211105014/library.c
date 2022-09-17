#include<stdio.h>
#include<stdbool.h>
#include<string.h>
typedef struct{
int accno;
char author[100];
int price;
bool isIssued;
char title[100];

}Book;


void newBook(Book *newbook,int bookNos);
void displayOneBook(Book *books);
void authorBooks(Book *books,int bookNos);
void displayAllBooks(Book *books,int bookNos);
void orderedBooks(Book *books,int bookNos);
int main(){
int choice;
int bookNos=0;
int *bookCounter = &bookNos;
Book books[100];
do{
printf("Welcome to GEC Library\n");
printf("Enter your choice\n");
printf("1.Enter new book details\n");
printf("2.Display all book info\n");
printf("3.List all books of specific author \n");
printf("4.List title of specific book \n");
printf("5.Display number of total books in library \n");
printf("6.List all books in order of accession no.\n");
printf("7.Exit\n");

scanf("%d",&choice);

switch(choice){

case 1:
newBook(&books[bookNos],bookNos);
bookNos++;
break;

case 2:
displayAllBooks(books,bookNos);
break;

case 3:
authorBooks(books,bookNos);
break;

case 4:
displayOneBook(books);
break;

case 5:
printf("Total No. of books: %d \n",bookNos);
break;

case 6:
orderedBooks(books,bookNos);
default:
printf("Enter valid choice. Please try again \n");

}

}while(choice!=7);
}


void newBook(Book *newbook,int bookNos){
printf("Enter book title\n");
scanf("%s",newbook->title);
printf("Enter price of book\n");
scanf("%d",&newbook->price);
printf("Enter author's name \n");
scanf("%s",newbook->author);
newbook->isIssued=false;
newbook->accno=bookNos;
printf("Book Acc No: %d \n",newbook->accno);

}

void displayAllBooks(Book *books,int bookNos){
int i;
printf("ALL BOOKS: \n\n");
for(i=0;i<bookNos;i++){
Book *newbook=&books[i];
printf("Book title: ");
printf(newbook->title);
printf("\n Price of book: %d \n",newbook->price);
printf("Author's name: ");
printf(newbook->author);
printf("\n");
printf("Book Acc No: %d \n",newbook->accno);
printf("\n");

}
printf("\n");
}

void displayOneBook(Book *books){
int num;
printf("Enter accession number\n");
scanf("%d",&num);
Book *newbook=&books[num];
printf("Book title: ");
printf(newbook->title);
printf("\n Price of book: %d \n",newbook->price);
printf("Author's name: ");
printf(newbook->author);
printf("\n");

}

void authorBooks(Book *books,int bookNos){
char author[100];
int i;
printf("Enter author's name\n");
scanf("%s",author);
for(i=0;i<bookNos;i++)
{Book *newbook=&books[i];
	if(strcmp(author,newbook->author)==0)
	{
		printf("Book title: ");
		printf(newbook->title);
		printf("\n Price of book: %d \n",newbook->price);
		printf("Book Acc No: %d \n",newbook->accno);
		break;

	}
	

}
printf("\n");
}

void orderedBooks(Book *books,int bookNos){
displayAllBooks(books,bookNos);
}



