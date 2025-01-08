
#ifndef CLSFINDUSERSCREEN_HPP
# define CLSFINDUSERSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankUser.hpp"
# include "clsUsersSuperScreen.hpp"

class clsFindUserScreen : protected clsUsersSuperScreen 
{

private:


public:

    static short   ShowFindUserScreen()
    {
        std::string Username;
        char    procceed_fl;

        drawScreensHeaders("Find User Screen");

        Username = InputValidator::readString("\n\nPlease enter the User's Username inorder to (Find):  ");

        while (!(clsBankUser::isUserExist(Username)))
        {    
            Username = InputValidator::readString("There is (No) Exist User with thid Username.\nPlease enter an (Exist Username) for a User or press (q) to quit:  ");
            procceed_fl = Username[0];
            if (tolower(procceed_fl) == 'q')
                return (1);                 //Quit using (q)
        }

        clsBankUser User = clsBankUser::Find(Username);

        if (User.isUserExist())
            std::cout << "\n\nUser Found.\n\n";
        else
            std::cout << "\n\nUser isn't Found.\n\n";

        printUserInfoCard(User);

        return (0);
    }    

};


# endif