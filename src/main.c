#include"banking.h"
int main()
{
        Account *head=NULL;
        Account *temp=NULL;
        char choice;
        while(1)
        {
                printf("c .createAccount p.displsy s.search  d.deposite  w.withdraw b.balance_enquiry t.transfer h.transaction_history l.loadAccount r.saveinformation e.exit\n");
                printf("enter the choice:");
                scanf(" %c",&choice);
                switch(choice)
                {
                        case'c':head=createAccount(head);
                                break;
                        case'p':display(head);
                                break;
                        case's':temp=searchAccount(head);
                                break;
                        case'd':deposite(head);
                                break;
                        case'w':withdraw(head);
                                break;
                        case'b':balance_enquiry(head);
                                break;
                        case't':transfer(head);
                                break;
                        case 'h':temp = searchAccount(head);
                                 if(temp != NULL)
                                 {
                                         displayTransaction(temp);
                                 }
                                 break;
                        case'r':saveAccounts(head);
                                break;
                        case'l':loadAccounts(&head);
                                break;
                        case'e':exit(0);
                }
        }
}
