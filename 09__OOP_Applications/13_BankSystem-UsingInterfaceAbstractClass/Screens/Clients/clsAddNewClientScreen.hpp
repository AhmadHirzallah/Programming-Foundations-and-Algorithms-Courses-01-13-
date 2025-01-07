
#pragma once

#ifndef CLSADDNEWCLIENTSCREEN_HPP 
# define CLSADDNEWCLIENTSCREEN_HPP 

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"
# include "clsClientsSuperScreen.hpp"



class clsAddNewClientScreen : protected clsClientsSuperScreen
{

public:

    static short   ShowAddNewClientScreen()
    {
        std::string ID_Nbr;
        char    procceed_fl;


        drawScreensHeaders("Add New Client Screen");

        procceed_fl = 'f';
        ID_Nbr = InputValidator::readString("\n\nPlease enter the ID Number of the Client:  ");
        while (clsBankClient::isClientExist(ID_Nbr))
        {    
            ID_Nbr = InputValidator::readString("There is a Exist Client with thid ID Number.\nPlease enter new ID Number of the Client or press (q) to quit:  ");
            procceed_fl = ID_Nbr[0];
            if (tolower(procceed_fl) == 'q')
                return (1);                 //Quit using (q)
        }   
        clsBankClient Client = clsBankClient::AddNewClient(ID_Nbr);
        if(inputReadingClientInfo(Client))
            return (1);                     //Stop Input return 
        if (Client.Save() == clsBankClient::en_SaveResults::SV_SUCCEEDED)
        {
            std::cout <<  "\nAccount Added Successfully :-)\n" << std::endl;
            printClientInfoCard(Client);
            return (0);
        }
        else
        {
            std::cout <<  "\nError account was NOT saved!" << std::endl;
            return (-1);
        }
    }



private:


};

# endif