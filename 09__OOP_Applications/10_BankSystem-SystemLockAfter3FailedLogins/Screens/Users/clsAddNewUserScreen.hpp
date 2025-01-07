#pragma once

#ifndef CLSADDNEWUSERSCREEN_HPP 
# define CLSADDNEWUSERSCREEN_HPP 


# include <cstdio>
# include <vector>
# include "../clsScreen.hpp"
# include "clsUsersSuperScreen.hpp"
# include "../../Core/clsBankUser.hpp"

class clsAddNewUserScreen : protected clsUsersSuperScreen
{
private:

//      //  //  

public:


    static short   ShowAddNewUserScreen()
    {
        std::string Username;
        char    procceed_fl;


        drawScreensHeaders("Add New User Screen");

        procceed_fl = 'f';
        Username = InputValidator::readString("\n\nPlease enter the Username of the new User:  ");
        while (clsBankUser::isUserExist(Username))
        {    
            Username = InputValidator::readString("There is a Exist User with thid ID Number.\nPlease enter new ID Number of the User or press (q) to quit:  ");
            procceed_fl = Username[0];
            if (tolower(procceed_fl) == 'q')
                return (1);                 //Quit using (q)
        }   

        clsBankUser User = clsBankUser::AddNewBankUser(Username);
        if(inputReadingUserInfo(User))
            return (1);                     //Stop Input return 
        if (User.Save() == clsBankUser::en_SaveResults::SV_SUCCEEDED)
        {
            std::cout <<  "\nAccount Added Successfully :-)\n" << std::endl;
            printUserInfoCard(User);
            return (0);
        }
        else
        {
            std::cout <<  "\nError account was NOT saved!" << std::endl;
            return (-1);
        }
    }

};



#endif