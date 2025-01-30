#ifndef CLSDELETECLIENTSCREEN_HPP
# define CLSDELETECLIENTSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"
# include "clsClientsSuperScreen.hpp"



class clsDeleteClientScreen : protected clsClientsSuperScreen
{
private:

//

public:

    static short   ShowDeleteClientScreen()
    {
        std::string ID_Nbr;
        char    procceed_fl;

        drawScreensHeaders("Delete Client Screen");

        procceed_fl = 'f';
        ID_Nbr = InputValidator::readString("\n\nPlease enter the ID Number of the Client inorder to (Delete):  ");

        while (!(clsBankClient::isClientExist(ID_Nbr)))
        {    
            ID_Nbr = InputValidator::readString("There is (No) Exist Client with thid ID Number.\nPlease enter an (Exist ID Number) for a Client or press (q) to quit:  ");
            procceed_fl = ID_Nbr[0];
            if (tolower(procceed_fl) == 'q')
                return (1);                 //Quit using (q)
        }  
        clsBankClient Client = clsBankClient::Find(ID_Nbr);

        printClientInfoCard(Client);

        std::cout << "Are you sure that you want to proceed (deleting) of the client (Press (q) to (quit)!)?  ";
        std::cin >> procceed_fl;
        if (tolower(procceed_fl) == 'q')
            return (2);
        if (!(Client.DeleteClient()))
        {
            std::cout << "\n\nClient is deleted Successfully!\n\n";
            printClientInfoCard(Client);
			std::cout << "\n\n___________________________" << std::endl;


            std::cout << "\n\nChecking if Client is exist in the Data File:";
//  Or We can Use this:
//          if (!(clsBankClient::isClientExist(ID_Nbr)))
            if (!(Client.isClientExist()))
            {
                std::cout << "\n\n(Succeed)! :)\nClient is not found in the Data files!\n\n";
                return (0);
            }
            else
            {
                std::cout << "\n\n\b(Unfortunately) Client is found in the Data files! :(";
                return (-1);        //	Client isn't Deleted
            }
        }
        return (3);
    }

};




# endif