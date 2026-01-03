#include <stdio.h>
void login();
void menu(int *balance);
void checkBalance(int balance);
void depositMoney(int *balance);
void withdrawMoney(int *balance);
void exitMessage();
int main()
{
login();
return 0;
}
void login()
{
int passcode=5236,entered;
int balance=10000;
for(int i=0;i<3;i++)
{
printf("Enter the password: ");
scanf("%d",&entered);
if(entered==passcode)
{
printf("\nLogin successful!\nInitial Balance: %d\n",balance);
menu(&balance);
return;
}
else
{
printf("Invalid password. Try again.\n");
}
}
printf("\n3 attempts only!!...\n");
}
void menu(int *balance)
{
int choice=0;
while(choice!=4)
{
printf("1) Check Balance\n");
printf("2) Deposit\n");
printf("3) Withdraw\n");
printf("4) Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:checkBalance(*balance);break;
case 2:depositMoney(balance);break;
case 3:withdrawMoney(balance);break;
case 4:exitMessage();break;
default:printf("Invalid choice! Enter between 1 to 4.\n");
}
}
}
void checkBalance(int balance)
{
printf("Your current balance is: %d\n",balance);
}
void depositMoney(int *balance)
{
int deposit;
printf("Enter the deposit amount: ");
scanf("%d",&deposit);
*balance+=deposit;
printf("Your balance after deposit: %d\n",*balance);
}
void withdrawMoney(int *balance)
{
int withdraw;
printf("Enter the withdrawal amount: ");
scanf("%d",&withdraw);
if(withdraw>*balance)
printf("Insufficient balance!\n");
else
{
*balance-=withdraw;
printf("Your balance after withdrawal: %d\n",*balance);
}
}
void exitMessage()
{
printf("\nProcessing in 3...\n2...\n1...\nTransaction Completed\n----------- EXIT -----------\n");
}
