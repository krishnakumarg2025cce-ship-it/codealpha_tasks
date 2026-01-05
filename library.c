#include <stdio.h>
#include <string.h>
#define MAX 100
struct Book{int id;char name[50];char author[50];int quantity;};
struct Book lib[MAX];
int count=0;
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
int main(){
int choice;
do{
printf("\n--- Library Management System ---\n");
printf("1.Add Book\n2.Display Books\n3.Search Book\n4.Issue Book\n5.Return Book\n0.Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);
switch(choice){
case 1:addBook();break;
case 2:displayBooks();break;
case 3:searchBook();break;
case 4:issueBook();break;
case 5:returnBook();break;
case 0:printf("Exiting...\n");break;
default:printf("Invalid choice\n");
}
}while(choice!=0);
return 0;
}
void addBook(){
printf("Enter Book ID: ");
scanf("%d",&lib[count].id);
printf("Enter Book Name: ");
scanf(" %[^\n]",lib[count].name);
printf("Enter Author Name: ");
scanf(" %[^\n]",lib[count].author);
printf("Enter Quantity: ");
scanf("%d",&lib[count].quantity);
count++;
printf("Book added successfully\n");
}
void displayBooks(){
int i;
if(count==0){printf("No books available\n");return;}
for(i=0;i<count;i++){
printf("\nID:%d\nName:%s\nAuthor:%s\nQuantity:%d\n",lib[i].id,lib[i].name,lib[i].author,lib[i].quantity);
}
}
void searchBook(){
int i,id,found=0;
printf("Enter Book ID to search: ");
scanf("%d",&id);
for(i=0;i<count;i++){
if(lib[i].id==id){
printf("Book Found\nName:%s\nAuthor:%s\nQuantity:%d\n",lib[i].name,lib[i].author,lib[i].quantity);
found=1;
break;
}
}
if(!found)printf("Book not found\n");
}
void issueBook(){
int i,id;
printf("Enter Book ID to issue: ");
scanf("%d",&id);
for(i=0;i<count;i++){
if(lib[i].id==id){
if(lib[i].quantity>0){lib[i].quantity--;printf("Book issued successfully\n");}
else printf("Book not available\n");
return;
}
}
printf("Book not found\n");
}
void returnBook(){
int i,id;
printf("Enter Book ID to return: ");
scanf("%d",&id);
for(i=0;i<count;i++){
if(lib[i].id==id){lib[i].quantity++;printf("Book returned successfully\n");return;}
}
printf("Book not found\n");
}

