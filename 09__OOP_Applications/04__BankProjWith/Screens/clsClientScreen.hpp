
#pragma once

#ifndef	CLSCLIENTSCREEN_HPP
# define	CLSCLIENTSCREEN_HPP


// # include "../../Include/"
# include "clsScreen.hpp"
# include "../Core/clsBankClient.hpp"
# include "../Include/CoreUtilities.hpp"





class	clsClientScreen: protected clsScreen
{

public:

			static void PrintClient(clsBankClient &Client)
			{
				std::cout << "\n\n" << CoreUtilities::Tabs(6) << "########################################";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "##                                    ##";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "##          ~ Client Card ~           ##";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "##                                    ##";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "########################################";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "|| FirstName       : " << Client.Firstname();
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "|| LastName        : " << Client.Lastname();
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "|| Full Name       : " << Client.Fullname();
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "|| Email           : " << Client.Email();
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "|| Phone           : " << Client.PhoneNbr();
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "-----------------------------------------";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "|| Account Number  : " << Client.AccountID();
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "|| Password        : " << Client.Password();
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "|| Balance         : " << Client.balance();
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "########################################";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "##        * End of Client Card *      ##";
				std::cout << "\n"    << CoreUtilities::Tabs(6) << "########################################\n";

				
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "Client Card:";
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "___________________";
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "FirstName   : " << Client.Firstname();
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "LastName    : " << Client.Lastname();
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "Full Name   : " << Client.Fullname();
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "Email       : " << Client.Email();
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "Phone       : " << Client.PhoneNbr();
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "Account Number : " << Client.AccountID();
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "Password    : " << Client.Password();
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "Balance     : " << Client.balance();
				// std::cout << "\n\n" << CoreUtilities::Tabs(6) << "___________________\n";
			}

};




# endif