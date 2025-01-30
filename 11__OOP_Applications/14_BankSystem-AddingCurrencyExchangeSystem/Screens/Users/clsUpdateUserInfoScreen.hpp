#pragma once

#ifndef CLSUPDATEUSERINFOSCREEN_HPP
# define CLSUPDATEUSERINFOSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankUser.hpp"
# include "clsUsersSuperScreen.hpp"

# include "../../Include/Global.hpp"

class clsUpdateUserInfoScreen : protected clsUsersSuperScreen 
{

private:

//

public:

    static short    ShowUpdateUserScreen()
    {
        std::string  Username;
        char    quit_fl = 'f';

        drawScreensHeaders("Update User Screen");

        Username = InputValidator::readString("\n\nPlease enter the Username:  ");

        while (!(clsBankUser::isUserExist(Username)))
        {
            Username = InputValidator::readString\
                ("Invalide Entered Username.\nPlease enter a Valid Username or Press (q) to quit:  ");
            quit_fl = tolower(Username[0]);
            if (quit_fl == 'q')
                return (2); // Indicating successful quit
        }


        clsBankUser   User = clsBankUser::Find(Username);

        printUserInfoCard(User);

        if (inputReadingUserInfo(User))
            return (1);

        if (User.Save() == clsBankUser::en_SaveResults::SV_SUCCEEDED)
        {
            std::cout <<  "\nAccount Updated Successfully :-)\n" << std::endl;
            if (g_ActiveUser.Username() == User.Username())
                g_ActiveUser = User;
            printUserInfoCard(User);
            return (0);     //Indicating success in update
        }
        else
        {
            std::cout <<  "\nError account Failed to save :-(\n" << std::endl;
            return (-1);
        }

        return (0);         //Indicating success in update
    }

};


# endif