#pragma once

#ifndef	CLSLOGINSCREEN_HPP
# define	CLSLOGINSCREEN_HPP

# include "../Include/CoreUtilities.hpp"
# include "../Include/DateUtils.hpp"
# include "../Include/InputValidator.hpp"
# include "../Include/StringUtils.hpp"
# include "clsScreen.hpp"

# include "../Include/Global.hpp"
# include "clsMainScreen.hpp"



class   clsLoginScreen : protected clsScreen
{

private:


    static void _Login()
    {
        std::string Username;
        std::string Password;
        short   LoginFailed = 1;

        while (LoginFailed)
        {
            Username = InputValidator::readString( ("\n" + CoreUtilities::Tabs(6) + "Enter Username:  "));
            if ((std::tolower(Username[0]) == 'q') && (Username.length() == 1))     //      Press q to qiot
                exit(-42);
            Password = InputValidator::readString((CoreUtilities::Tabs(6) + "Enter Password:  "));

            g_ActiveUser = clsBankUser::Find(Username, Password);

            if (!(g_ActiveUser.isUserExist()))
            {
                std::cout  << "\n\n" << CoreUtilities::Tabs(6) << "Invalid Username or Password!"\
                            << "\n" << CoreUtilities::Tabs(6) << "Enter them again or enter (q) to Quit:\n\n";
            }
            else
                LoginFailed = 0;        //      User Found Successfully
        }
    }




public: 

    static void ShowLoginScreen()
    {
		system("clear");

        drawScreensHeaders("Login Screen ...");

        _Login();
        
        clsMainScreen::showMainMenu();
        
    }

};


#endif