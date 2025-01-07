
#ifndef CLSFINDCLIENTSCREEN_HPP
# define CLSFINDCLIENTSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"
# include "clsClientsSuperScreen.hpp"

class clsFindClientScreen : protected clsClientsSuperScreen 
{

private:


public:

    static short   ShowFindClientScreen()
    {
        std::string ID_Nbr;
        char    procceed_fl;

        drawScreensHeaders("Find Client Screen");

        ID_Nbr = InputValidator::readString("\n\nPlease enter the ID Number of the Client inorder to (Find):  ");

        while (!(clsBankClient::isClientExist(ID_Nbr)))
        {    
            ID_Nbr = InputValidator::readString("There is (No) Exist Client with thid ID Number.\nPlease enter an (Exist ID Number) for a Client or press (q) to quit:  ");
            procceed_fl = ID_Nbr[0];
            if (tolower(procceed_fl) == 'q')
                return (1);                 //Quit using (q)
        }

        clsBankClient Client = clsBankClient::Find(ID_Nbr);

        if (Client.isClientExist())
            std::cout << "\n\nClient Found.\n\n";
        else
            std::cout << "\n\nClient isn't Found.\n\n";

        printClientInfoCard(Client);

        return (0);
    }    

};


# endif