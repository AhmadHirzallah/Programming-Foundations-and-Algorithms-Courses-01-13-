#pragma once

#ifndef	CLSADDNEWCLIENTSCREEN_HPP
# define	CLSADDNEWCLIENTSCREEN_HPP


// # include "../../Include/"
# include "../../Core/clsBankClient.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../clsScreen.hpp"
# include "clsShowClientsScreen.hpp"
# include "../clsClientScreen.hpp"
# include "iomanip"





class	clsAddNewClientScreen : protected clsClientScreen
{

private:

			static void	_ReadClientInfo(clsBankClient &Client)
			{
				std::cout << CoreUtilities::Tabs(6);
				Client.setFirstname(InputValidator::readString("Enter First Name: "));
				std::cout << CoreUtilities::Tabs(6);
				Client.setLastname(InputValidator::readString("Enter Last Name: "));
				std::cout << CoreUtilities::Tabs(6);
				Client.setPassword(InputValidator::readString("Enter Password: "));
				std::cout << CoreUtilities::Tabs(6);
				Client.setEmail(InputValidator::readString("Enter Email Address: "));
				std::cout << CoreUtilities::Tabs(6);
				Client.setPhoneNbr(InputValidator::readString("Enter Phone Number: "));
				std::cout << CoreUtilities::Tabs(6);
				Client.setBalance(InputValidator::readPositiveNumber_Var<double>("Enter the Balance: "));
			}

			static void	_PrintSaveResult(clsBankClient::e_save_result SaveResult)
			{
				if (SaveResult == clsBankClient::e_save_result::SV_FAIL_ACCOUNT_NBR_USED)
					std::cout << "\nError account was not saved; because account number is in use!\n";
				else if (SaveResult == clsBankClient::e_save_result::SV_FAIL_EMPTY_OBJ)
					std::cout << "\nError account was not saved because it's Empty (No Data/Empty Object)!\n";
				else if (SaveResult == clsBankClient::e_save_result::SV_SUCCEEDED)
					std::cout << "\n" << CoreUtilities::Tabs(6) << "Account Addeded Successfully :-)\n";
				else
					return ;
			}
	
public:
			static void	ShowAddNewClientScreen()
			{
				std::string	AccountIDNbr = "";
				clsBankClient::e_save_result	SaveResult;

				drawScreensHeaders("Add New Client Screen");

				do
				{
					AccountIDNbr = InputValidator::readString("\n\t\t\t\t\t\tPlease enter the Account Number: ");
					if (clsBankClient::isClientExist(AccountIDNbr))
						std::cout << std::endl << CoreUtilities::Tabs(6) << "Number is existed!";

				}				while (clsBankClient::isClientExist(AccountIDNbr));

				clsBankClient	NewClient = clsBankClient::addNewClientObj(AccountIDNbr);
				_ReadClientInfo(NewClient);

				SaveResult = NewClient.Save();
				_PrintSaveResult(SaveResult);
			}


};




# endif