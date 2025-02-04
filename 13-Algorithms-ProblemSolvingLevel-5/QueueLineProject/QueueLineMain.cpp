
#include <iostream>
#include <windows.h>        // for sleep in windows
#include "clsQueueLine.hpp"

int main()
{
    system("clear");
    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);
   

    PayBillsQueue.IssueTicket();        Sleep(2000);  // Wait for 2000 milliseconds (2 seconds)
    PayBillsQueue.IssueTicket();        Sleep(5000);  // Waiting 5 Seconds
    PayBillsQueue.IssueTicket();        Sleep(3000);
    PayBillsQueue.IssueTicket();        Sleep(2500);
    PayBillsQueue.IssueTicket();        Sleep(5000);

    std::cout << "\n\n\n\n" << StringUtils::Tabs(7) << "****** Pay Bills Queue Info: ******\n";
    PayBillsQueue.PrintInfo();

    PayBillsQueue.PrintTicketsRTL();
    PayBillsQueue.PrintTicketsLTR();



    PayBillsQueue.PrintAllTickets();
 
    PayBillsQueue.ServeNextClient();
    std::cout << "\n\n\n\n" << StringUtils::Tabs(7) << "****** Pay Bills Queue After Serving One client ********\n";
    PayBillsQueue.PrintInfo();

    std::cout << "\n\n\n\n" << StringUtils::Tabs(7) << "******* Subscriptions Queue Info: ******** \n";

    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
   
  
    SubscriptionsQueue.PrintInfo();

    SubscriptionsQueue.PrintTicketsRTL();
    SubscriptionsQueue.PrintTicketsLTR();
 
    SubscriptionsQueue.PrintAllTickets();
    
    SubscriptionsQueue.ServeNextClient();
    std::cout << "\n\n\n\n" << StringUtils::Tabs(7) << "***** Subscriptions Queue After Serving One client *****\n";
    SubscriptionsQueue.PrintInfo();


    return 0;
}