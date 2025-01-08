
#pragma once

#ifndef CLSDEPOSITSCREEN_HPP 
# define CLSDEPOSITSCREEN_HPP 

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"

# include "../Clients/clsClientsSuperScreen.hpp"

class clsDepositScreen : protected clsClientsSuperScreen
{

    private:

    //
        
    public:

            static void showDepositScreen()
            {

                std::string ID_Nbr;
                char    procceed_fl;
                double  deposit_value;

                drawScreensHeaders("Money Deposition");

                ID_Nbr = InputValidator::readString("\n\nPlease enter the ID Number of the Client inorder to (Find):  ");

                while (!(clsBankClient::isClientExist(ID_Nbr)))
                {    
                    ID_Nbr = InputValidator::readString(
                "There is (No) Exist Client with thid ID Number.\nPlease enter an (Exist ID Number) for a Client or press (q) to quit:  "
                                                        );
                    procceed_fl = ID_Nbr[0];
                    if (tolower(procceed_fl) == 'q')
                        return ;                 //Quit using (q)
                }

                clsBankClient Client = clsBankClient::Find(ID_Nbr);

                printClientInfoCard(Client);

                procceed_fl = InputValidator::readChr("\n\nAre you sure that you want to proceed and Perform this Deposit (y to continue)?  ");

                if (tolower(procceed_fl) != 'y')
                    return ;

                deposit_value = InputValidator::readRangedNumberDouble(0, (std::numeric_limits<double>::max()),
                                                                                 "\nPlease enter the Amount inorder to Deposit ($):  ");
                

                if (!(Client.Deposit(deposit_value)))
                    std::cout << "\n\nMoney added Successfully.\n\nBalance after:  " << Client.balance() << " $" << std::endl << std::endl;
                else
                    std::cout << "\n\nUnfortunately, Failed to add the Money." << std::endl << std::endl;

                return ;
            }    

};


# endif