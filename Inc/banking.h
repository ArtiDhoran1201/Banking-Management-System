#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Transaction
{
        int transaction_id;
        char type[20];
        float amount;
} Transaction;
typedef struct Account
{
        char name[100];
        int account_No;
        float balance;
        char Contact[11];
        Transaction transactions[5];
        int transaction_count;
        struct Account *link;
}Account;
Account* createAccount(Account *);
void display(Account*);
Account *searchAccount(Account *);
void deposite(Account *);
void withdraw(Account *);
void balance_enquiry(Account *);
void transfer(Account *);
void storeTransaction(Account *, char *, float);
void displayTransaction(Account *);
void saveAccounts(Account *);
void loadAccounts(Account **);
