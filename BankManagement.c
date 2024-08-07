#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account {
    int id;
    char name[20];
    char pass[20];
    int balance;
};

void intro();
void createAcc(struct Account a[],int *i);
void loginAcc(struct Account a[],int *i);
void login(struct Account a[],int *i);
void display(struct Account a[],int *i);
void loginIntro();

int main() {
    struct Account a[10];
    int i=0,j=0;
    for(int j=0;j<10;j++) {
        a[j].id = -1;
    }
    while(1)
    {
        int x;
        intro();
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                createAcc(a,&i);
                break;
            case 2:
                loginAcc(a,&i);
                break;
            case 3:
                exit(1);
            default:
                printf("Enter valid operation.");
                break;
        }
    }
    return 0;
}

void intro() {
    printf("\n\nBank Management System\n\n");
    printf("1. Create New Account : \n");
    printf("2. Account Login\n");
    printf("3. Exit \n");
    printf("Enter Operation : ");
}

void createAcc(struct Account a[],int *i) {
    if(*i >= 10)
    {
        printf("Sorry for inconvenience\n");
        return;
    }
    else
    {
        int j=*i;
        printf("\n\nCreate Account : \n\n");
        printf("Enter 4-digit Code : ");
        scanf("%d",&a[*i].id);
        printf("Enter your name : ");
        scanf("%s",&a[*i].name);
        printf("Enter the password : ");
        scanf("%s",&a[*i].pass);
        printf("Enter your Deposit Amount : ");
        scanf("%d",&a[*i].balance);
        (*i)++;
        login(a,&j);
    }
}

void loginAcc(struct Account a[],int *i) {
    if(*i == -1)
    {
        printf("First Create Account");
        return;
    }
    else
    {
        int id,f=0,j=0;
        char pass[20];
        printf("Enter id : ");
        scanf("%d",&id);
        printf("Enter password : ");
        scanf("%s",&pass);
        for(int j = 0; j < *i; j++) {
            if(id == a[j].id && strcmp(a[j].pass, pass) == 0) {
                login(a, &j); 
                return;
            }
            else
            {
                printf("invalid Login");
            }
        }
    }
}

void login(struct Account a[],int *i)
{
    display(a,i);
    while(1)
    {
        int ch,amount;
        loginIntro();
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                a[*i].balance += amount;
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                if (amount > a[*i].balance) {
                    printf("Insufficient funds.\n");
                } else {
                    a[*i].balance -= amount;
                    printf("Withdrew %d.\n", amount, a[*i].balance);
                }
                break;
            case 3:
                printf("Account Balance: %d\n", a[*i].balance);
                break;
            case 4:
                return;
            default:
                printf("Enter valid operation. ");
                break;
        }
    }
}

void loginIntro()
{
    printf("Account Operaions : \n");
    printf("1. Deposite \n");
    printf("2. Withdraw \n");
    printf("3. Check Balance \n");
    printf("4. Logout \n");
    printf("Enter Operation : ");
}

void display(struct Account a[],int *i) {
    printf("\n\nAccount details : \n\n");
    printf("Account holder : %s\n",a[*i].name);
    printf("Account id : %d\n",a[*i].id);
    printf("Account Balance : %d\n\n",a[*i].balance);
}
