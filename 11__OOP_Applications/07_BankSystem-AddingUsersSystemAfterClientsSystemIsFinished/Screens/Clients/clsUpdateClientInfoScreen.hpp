#pragma once

#ifndef CLSUPDATECLIENTINFOSCREEN_HPP
# define CLSUPDATECLIENTINFOSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"
# include "clsClientsSuperScreen.hpp"

class clsUpdateClientInfoScreen : private clsClientsSuperScreen 
{

private:

//

public:

    static short    ShowUpdateClientScreen()
    {
        std::string  AccNbr;
        char    quit_fl = 't';

        drawScreensHeaders("Update Client Screen");

        AccNbr = InputValidator::readString("\n\nPlease enter the Account Number:  ");
        while (!(clsBankClient::isClientExist(AccNbr)))
        {
            AccNbr = InputValidator::readString("Invalide Entered Number.\nPlease enter the Account Number Again or Press (q) to quit:  ");
            quit_fl = tolower(AccNbr[0]);
            if (quit_fl == 'q')
                return (2); // Indicating successful quit
        }
        clsBankClient   Client = clsBankClient::Find(AccNbr);

        printClientInfoCard(Client);

        if (inputReadingClientInfo(Client) == 1)
            return (1);

        if (Client.Save() == clsBankClient::en_SaveResults::SV_SUCCEEDED)
        {
            std::cout <<  "\nAccount Updated Successfully :-)\n" << std::endl;
            printClientInfoCard(Client);
            return (0);
        }
        else if (Client.Save() != clsBankClient::en_SaveResults::SV_SUCCEEDED)
        {
            std::cout <<  "\nError account was not saved because it's Empty" << std::endl;
            return (-1);
        }

        return (0); //Indicating success in update
    }

};


# endif