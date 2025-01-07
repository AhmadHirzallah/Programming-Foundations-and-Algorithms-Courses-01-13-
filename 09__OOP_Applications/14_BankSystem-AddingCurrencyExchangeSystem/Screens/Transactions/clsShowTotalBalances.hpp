
#pragma once

#ifndef CLSSHOWTOTALBALANCES_HPP
# define CLSSHOWTOTALBALANCES_HPP 

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"

class clsShowTotalBalances: protected clsScreen
{

    private:

            static void    _ListOneBalanceRecordOfClient(clsBankClient &Client)
            {
                printf("| %-25s | %-25s | %-25s | %-50s | %-40.5f \n", 
                Client.AccountID().c_str(),
                    Client.Firstname().c_str(),
                    Client.Lastname().c_str(),
                    Client.Fullname().c_str(),
                    Client.balance());
            }
        
    public:


            static short   ShowTotalBalancesOfClientsScreen()
            {
                std::vector <clsBankClient> ClientsList = clsBankClient::GetClientsListToVect();
                double  total_balances = clsBankClient::CalculateTotalBalancesOfClients();
                // std::vector <clsBankClient> ClientsList ;        //Test 0 Clients Display

                std::string subtitle = "(" + std::to_string(ClientsList.size()) + ") Client(s)" ;

                drawScreensHeaders("Balances List Screen", subtitle);

                printf("| %-25s | %-25s | %-25s | %-50s | %-40s", 
                "Account Number", "First Name", "Last Name", "Full Name", "Balance");
                printf("\n________________________________________________________________________________________________________________________________________________________\n");

                if (ClientsList.size() < 1)
                {
                    std::cout << "\n\n\n\t\t\t\t\t\t\tThere is (No) Clients Avialable in the System :( :( : (\n\n\n";
                    printf("________________________________________________________________________________________________________________________________________________________\n");
                    printf("________________________________________________________________________________________________________________________________________________________\n\n\n");
                    return (-1);            //      No Clients Avialable.
                }

                for (clsBankClient &Client: ClientsList)
                    _ListOneBalanceRecordOfClient(Client);

                printf("________________________________________________________________________________________________________________________________________________________\n");
                printf("________________________________________________________________________________________________________________________________________________________\n\n\n");

                printf("%75s (%f)\n", "Total Balances: ", total_balances);
                printf("%106s \n\n\n", CoreUtilities::NumberToText((long)total_balances).c_str());

                return (0);
            }

};


# endif


/*

                printf("\n\t\t\t__________________________________________________________________________________________________________________\n");
                printf("\t\t\t__________________________________________________________________________________________________________________\n");
                printf("\n\t\t\t\t\t\t\t\t\tClient List (%zu) Client(s).\n", ClientsList.size());
                printf("\t\t\t__________________________________________________________________________________________________________________\n");
                printf("\n\n_________________________________________________________________________________________________________________________________________________________\n");
*/