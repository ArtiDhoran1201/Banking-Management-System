#include"banking.h"
void transfer(Account *head)
{
        printf("--------TRANSFER MONEY--------\n");
        Account *sender=NULL;
        Account *reciver=NULL;
        if(head==NULL)
        {
                printf("list is empty....\n");
                return;
        }
        printf("enter the sender account no:\n");
        sender=searchAccount(head);
        if(sender==NULL)
        {
                printf("sender account not found\n");
                return;
        }
        printf("enter the receiver account no:\n");
        reciver=searchAccount(head);
        if(reciver==NULL)
        {
                printf("reciver account not found\n");
                return ;
        }
        if(sender==reciver)
        {
                printf("Cannot transfer to the same account\n");
                return;
        }
        float Ammount;
        printf("enter the ammount:");
        scanf("%f",&Ammount);
        if(Ammount<=0)
        {
                printf("invalid ammount\n");
                return;
        }
        if(Ammount<=sender->balance)
        {
                sender->balance=sender->balance-Ammount;
                reciver->balance=reciver->balance+Ammount;
        }
        else
        {
                printf("insufficient balance\n");
                return;
        }
        storeTransaction(sender, "TRANSFER OUT", Ammount);
        storeTransaction(reciver, "TRANSFER IN", Ammount);

}
/*void storeTransaction(Account *acc,char *type,float amount)
{
      int i = acc->transaction_count;
      if(acc->transaction_count>=5)
      {
          printf("transaction history is full\n");
          return;
      }
      acc->transactions[i].transaction_id = i + 1;
      strcpy(acc->transactions[i].type, type);
      acc->transactions[i].amount = amount;
      acc->transaction_count++;
}*/
void storeTransaction(Account *acc, char *type, float amount)
{
    if(acc->transaction_count < 5)
    {
        int i = acc->transaction_count;

        acc->transactions[i].transaction_id = i + 1;
        strcpy(acc->transactions[i].type, type);
        acc->transactions[i].amount = amount;

        acc->transaction_count++;
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            acc->transactions[i] = acc->transactions[i + 1];
        }

        acc->transactions[4].transaction_id = 5;
        strcpy(acc->transactions[4].type, type);
        acc->transactions[4].amount = amount;
    }
}
void displayTransaction(Account *acc)
{

        printf("--------TRANSACTION HISTORY--------\n");
    int i;
    if(acc->transaction_count == 0)
    {
        printf("No transaction history\n");
        return;
    }

    for(i = 0; i < acc->transaction_count; i++)
    {
        printf("%d\t%s\t%.2f\n",acc->transactions[i].transaction_id,acc->transactions[i].type,acc->transactions[i].amount);
    }
}
