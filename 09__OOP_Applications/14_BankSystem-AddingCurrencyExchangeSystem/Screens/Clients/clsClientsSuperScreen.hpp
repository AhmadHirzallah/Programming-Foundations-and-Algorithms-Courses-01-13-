#pragma once

#ifndef CLSCLIENTSSUPERSCREEN_HPP
# define	CLSCLIENTSSUPERSCREEN_HPP

# include <iostream>
# include "../clsScreen.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../../Core/clsBankClient.hpp"

class	clsClientsSuperScreen : protected clsScreen
{

protected:


			//				Used in: clsAddNewClient
			static short   inputReadingClientInfo(clsBankClient &Client)
			{
				char    proceed_fl = 'n';

				std::cout <<"\n\nPlease if you want to continue enter (y):  ";
				std::cin >> proceed_fl;
				if (tolower(proceed_fl) != 'y')
					return (1);                     //      Stop Input return

				Client.setFirstname(InputValidator::readString("\n\nPlease enter First Name: "));
				Client.setLastname(InputValidator::readString("Please enter Last Name: "));
				Client.setEmail(InputValidator::readString("Please enter Email: "));
				Client.setPhoneNbr(InputValidator::readString("Please enter Phone Number: "));
				Client.setPassword(InputValidator::readString("Please enter Password: "));
				Client.setBalance(InputValidator::readRangedNumberDouble(0, std::numeric_limits<double>::max(), "Please enter the Balance: "));
				return (0);
			}


			// Used For : 
			static void    printClientInfoCard(clsBankClient &Client)
			{
				int cardWidth = 45;  // Width of the card block
				int totalWidth = 160; // Total terminal width
				int padding = (totalWidth - cardWidth) / 2;  // Padding for centering the card block

				std::cout << "\n\n";
				std::cout << std::setw(padding) << std::right << "" << "Client Card:" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "First Name   : " << Client.Firstname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Last Name    : " << Client.Lastname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Full Name    : " << Client.Fullname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Email        : " << Client.Email() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Phone        : " << Client.PhoneNbr() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Acc. Number  : " << Client.AccountID() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Password     : " << Client.Password() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Balance      : " << std::fixed << std::setprecision(5) 
						<< Client.balance() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::endl;
			}

			static void    printClientCard_EssintialInfo(std::string ID_Nbr)
			{
				int cardWidth = 45;  // Width of the card block
				int totalWidth = 160; // Total terminal width
				int padding = (totalWidth - cardWidth) / 2;  // Padding for centering the card block

				clsBankClient Client = clsBankClient::Find(ID_Nbr);
				std::cout << "\n\n";
				std::cout << std::setw(padding) << std::right << "" << "Client Card:" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Acc. Number  : " << Client.AccountID() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Full Name    : " << Client.Fullname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Phone        : " << Client.PhoneNbr() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Balance      : " << std::fixed << std::setprecision(5) 
						<< Client.balance() << "$" <<std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::endl;
			}




};



#endif