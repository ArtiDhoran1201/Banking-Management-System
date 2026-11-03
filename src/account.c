#include "banking.h"
Account* createAccount(Account *head)
{
        printf("--------CREATE NEW ACCOUNT--------\n");
        Account* newnode,*temp=NULL;
        newnode=calloc(1,sizeof(Account));
        if(newnode==NULL)
        {
                printf("newnode is create\n");
                return head;
        }
        temp=head;
        printf("enter the name:");
        scanf("%s",newnode->name);
        printf("enter the Account number:");
        scanf("%d",&newnode->account_No);
        printf("enter the contact No:");
        scanf("%10s",newnode->Contact);
        printf("enter the balance:");
        scanf("%f",&newnode->balance);
        while(temp!=NULL)
        {
                if(temp->account_No==newnode->account_No)
                {
                        printf("account No is already exists\n");
                        free(newnode);
                        return head;
                }
                temp=temp->link;
        }
        newnode->link=head;
        head=newnode;
        return head;
}
Account *searchAccount(Account *head)
{
        printf("--------SEARCH ACCOUNT--------\n");
        int Ac;
        printf("enter the account:");
        scanf("%d",&Ac);
        Account *temp=NULL;
        if(head==NULL)
        {
                printf("list is empty..\n");
                return NULL;
        }
        else
        {
                temp=head;
                while(temp)
                {
                        if(temp->account_No==Ac)
                        {
                                printf("%s %d %s %f\n",temp->name,temp->account_No,temp->Contact,temp->balance);
                                return temp;
                        }
                        temp=temp->link;
                }
        }
        printf("Account is not found\n");
        return NULL;
}
void deposite(Account *head)
{
        printf("--------DEPOSITE AMMOUNT--------\n");
        Account *temp=searchAccount(head);
        if(temp==NULL)
        {
                printf("Account is not found\n");
                return ;
        }
        float new_balance;
        printf("enter the new balance:");
        scanf("%f",&new_balance);
        if(new_balance<=0)
        {
                printf("the ammount is not valid\n");
                return;
        }
        temp->balance=temp->balance+new_balance;
        printf("Upadted Balance:%.2f\n",temp->balance);
        storeTransaction(temp,"DEPOSITE",new_balance);
}
void withdraw(Account *head)
{
        printf("--------WITHDRAW MONEY--------\n");
        Account *temp=searchAccount(head);
        if(temp==NULL)
         {
                 printf("Account is not found\n");
                 return ;
         }
        float Ammount;
        printf("enter the new Ammount:");
        scanf("%f",&Ammount);
        if(Ammount<=0)
        {
                printf("the ammount is not valid:\n");
                return;
        }
        if(Ammount<=temp->balance)
        {
                temp->balance=temp->balance-Ammount;
                printf("remaining balance:%.2f\n",temp->balance);
                storeTransaction(temp,"WITHDRAW",Ammount);
        }
        else
        {
                printf("balance is insufficient...\n");
        }
}
void balance_enquiry(Account *head)
{
        printf("--------BALANCE ENQUIRY--------\n");
        Account *temp=NULL;
        temp=searchAccount(head);
        if(temp==NULL)
        {
                printf("invalid\n");
                return;
        }
        printf("Available balanc:%f\n",temp->balance);

}
void saveAccounts(Account *head)
{
        FILE *fp=NULL;
        fp=fopen("account.txt","w");
        if(fp==NULL)
        {
                printf("invalid:");
                return;
        }
        else
        {
                Account *temp=NULL;
                temp=head;
                while(temp)
                {
                        fprintf(fp, "%s %d %s %f\n", temp->name,temp->account_No,temp->Contact,temp->balance);
                        temp=temp->link;
                }
        }
        fclose(fp);
        printf("store information successfully...\n");
}
void loadAccounts(Account **head)
{
    FILE *fp = fopen("account.txt", "r");

    if(fp == NULL)
    {
        printf("No saved account file found\n");
        return;
    }

    Account *temp;
    Account *last = *head;
    while(last != NULL && last->link != NULL)
    {
            last = last->link;
    }
    while(1)
    {
        temp = calloc(1, sizeof(Account));

        if(temp == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }
        if(fscanf(fp, "%99s  %d   %10s  %f",temp->name,&temp->account_No,temp->Contact,&temp->balance )!= 4)
        {
            free(temp);
            break;
        }

        temp->link = NULL;

        if(*head == NULL)
        {
            *head = temp;
        }
        else
        {
            last->link = temp;
        }

        last = temp;
    }

    fclose(fp);

    printf("Accounts loaded successfully!\n");
}
void display(Account *head)
{
        printf("--------DISPLAY BANK INFORMATION--------\n");
        if(head==NULL)
        {
                printf("list is empty..\n");
        }
        else
        {
                while(head)
                {
                        printf("%s     %d     %s     %f\n",head->name,head->account_No,head->Contact,head->balance);
                        head=head->link;
                }
	}
}
