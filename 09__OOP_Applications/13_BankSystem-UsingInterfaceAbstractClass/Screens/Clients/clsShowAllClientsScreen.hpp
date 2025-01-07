#pragma once

#ifndef CLSSHOWALLCLIENTSSCREEN_HPP
# define CLSSHOWALLCLIENTSSCREEN_HPP

# include <vector>
# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"
# include "clsClientsSuperScreen.hpp"



class clsShowAllClientsScreen : protected clsClientsSuperScreen 
{

    private:

        static void    ListOneClient(clsBankClient &Client)
        {
            printf("| %-15s | %-22s | %-15s | %-15s | %-30s | %-18s | %-15.2f |\n", 
                Client.AccountID().c_str(),
                Client.Password().c_str(), 
                Client.Firstname().c_str(), 
                Client.Lastname().c_str(), 
                Client.Email().c_str(), 
                Client.PhoneNbr().c_str(), 
                Client.balance());
        }

    public:

        static short    ShowClientsListScreen()
        {
            std::vector ClientsList = clsBankClient::GetClientsListToVect();
            // std::vector <clsBankClient> ClientsList ;        //Test 0 Clients Display

            std::string subtitle = "(" + std::to_string(ClientsList.size()) + ") Client(s)" ;


            drawScreensHeaders("List Clients Screen", subtitle);
           
            printf("| %-15s | %-22s | %-15s | %-15s | %-30s | %-18s | %-15s |\n", 
            "Account Number", "Pin Code", "First Name", "Last Name", "Email", "Phone", "Balance");
           
            printf("________________________________________________________________________________________________________________________________________________________\n");

            if (ClientsList.size() < 1)
            {
                std::cout << "\n\n\n\t\t\t\t\t\t\tThere is (No) Clients Avialable in the System :( :( : (\n\n\n";
                printf("________________________________________________________________________________________________________________________________________________________\n");
                printf("________________________________________________________________________________________________________________________________________________________\n\n\n");

                return (-1);            //      No Clients Avialable.
            }
            for (clsBankClient &Client: ClientsList)
                ListOneClient(Client);

            printf("________________________________________________________________________________________________________________________________________________________\n");
            printf("________________________________________________________________________________________________________________________________________________________\n");
            printf("________________________________________________________________________________________________________________________________________________________\n\n\n");

            return (0);                 //      Everything Worked Correctly.
        }

};





#endif
/*
            printf("\n\t\t\t__________________________________________________________________________________________________________________\n");
            printf("\t\t\t__________________________________________________________________________________________________________________\n");
            printf("\n\t\t\t\t\t\t\t\t\tClient List (%zu) Client(s).\n", ClientsList.size());
            printf("\t\t\t__________________________________________________________________________________________________________________\n");
            printf("\n\n________________________________________________________________________________________________________________________________________________________\n");
*/