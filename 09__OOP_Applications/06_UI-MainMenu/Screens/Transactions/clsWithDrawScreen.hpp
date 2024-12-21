
#pragma once

#ifndef CLSWITHDRAWSCREEN_HPP
# define  CLSWITHDRAWSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"

class clsWithDrawScreen : protected clsScreen
{

    private:

    //
        
    public:

            static void showWithDrawScreen()
            {

                std::string ID_Nbr;
                char    procceed_fl;
                double  withdraw_val;

                drawScreensHeaders("Money Withdraw");

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

                procceed_fl = InputValidator::readChr("\n\nAre you sure that you want to proceed and (Withdraw) from the Client (q to quit)?  ");
                if (tolower(procceed_fl) == 'q')
                    return ;
                
                withdraw_val = InputValidator::readRangedNumberDouble(0, std::numeric_limits<double>::max(),
                                                                                 "\nPlease enter the Amount inorder to withdraw ($):  ");
                
                while (1)
                {
                    if (Client.Withdraw(withdraw_val))
                    {
                        std::cout << "\n\nUnfortunately, Failed to Withdraw the Money." << std::endl;
                         withdraw_val = InputValidator::readRangedNumberDouble(0, std::numeric_limits<double>::max(),
                                                                                "\nPlease enter a valid Amount inorder to withdraw ($):  ");
                    }
                    else
                    {
                        std::cout << "\n\nMoney Withdrawed Successfully.\n\nBalance after:  " << Client.balance() << " $" << std::endl << std::endl;
                        return ;
                    }
                }
                return ;
            }    

};


# endif