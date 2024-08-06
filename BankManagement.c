#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    int balance;
    char pass[20];
} Client;

void display(const Client *c);
void operations();
void deposite(Client *c);
void withdraw(Client *c);

int main() {
    Client c;
    c.id = 101;
    printf("Enter your name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; 

    printf("Enter password: ");
    fgets(c.pass, sizeof(c.pass), stdin);
    c.pass[strcspn(c.pass, "\n")] = '\0';

    printf("How much cash do you want to deposit: ");
    scanf("%d", &c.balance);

    display(&c);
    
    while(1)
    {
        operations();
        int ch;
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                deposite(&c);
                break;
            case 2:
                withdraw(&c);
                break;
            case 3:
                display(&c);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid operation.\n");
                break;
        }
    }
    return 0;
}

void display(const Client *c) {
    printf("\n\nClient ID: %d\n", c->id);
    printf("Client Name: %s\n", c->name);
    printf("Account Balance: %d\n", c->balance);
}

void operations() {
    printf("\n\nSimple Bank Management System\n");
    printf("Operations:\n");
    printf("1. Deposit money\n");
    printf("2. Withdraw money\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
}

void deposite(Client *c) {
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    c->balance += amount;
}

void withdraw(Client *c) {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    if (amount > c->balance) {
        printf("Insufficient funds.\n");
    } else {
        c->balance -= amount;
        printf("Withdrew %d.\n", amount, c->balance);
    }
}