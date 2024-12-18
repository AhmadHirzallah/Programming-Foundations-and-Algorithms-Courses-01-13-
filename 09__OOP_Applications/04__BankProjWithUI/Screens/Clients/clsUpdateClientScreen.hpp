#pragma once

#ifndef	CLSUPDATECLIENTSCREEN_HPP
# define	CLSUPDATECLIENTSCREEN_HPP


// # include "../../Include/"
# include "../../Core/clsBankClient.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../clsScreen.hpp"
# include "clsShowClientsScreen.hpp"
# include "../clsClientScreen.hpp"
# include "iomanip"





class	clsUpdateClientScreen : protected clsClientScreen
{

private:


			static void	_ReadUpdatingClientInfo(clsBankClient &ClientToUpdate)
			{
				system("clear");
				std::cout << CoreUtilities::Tabs(7);
				printf("---       Update The Client Info:       ---\n");
				std::cout << "\n";
				std::cout << CoreUtilities::Tabs(7);
				ClientToUpdate.setFirstname(InputValidator::readString("Please enter the First Name: "));
				std::cout << "\n";
				std::cout << CoreUtilities::Tabs(7);
				ClientToUpdate.setLastname(InputValidator::readString("Please enter the Last Name: "));
				std::cout << "\n";
				std::cout << CoreUtilities::Tabs(7);
				ClientToUpdate.setEmail(InputValidator::readString("Please enter the Email Address: "));
				std::cout << "\n";
				std::cout << CoreUtilities::Tabs(7);
				ClientToUpdate.setPhoneNbr(InputValidator::readString("Please enter the Phone Number: "));
				std::cout << "\n";
				std::cout << CoreUtilities::Tabs(7);
				ClientToUpdate.setPassword(InputValidator::readString("Please enter the Password!! : "));
				std::cout << "\n";
				std::cout << CoreUtilities::Tabs(7);
				ClientToUpdate.setBalance(InputValidator::readPositiveNumber_Var <double> ("Please enter the Balance: "));
			}

			static void	_PrintUpdateResult(clsBankClient::e_save_result	Saving)
			{
				if (Saving == clsBankClient::e_save_result::SV_SUCCEEDED)
					printf("\n\t\t\t\t\t\t\tAccount Updated Successfully :-) .\n");
				else
					printf("\nError account was not Updated :-( .\n");
			}
public:

			static void	ShowUpdateClientScreen()
			{
				std::string	ID_ToUpdate = "";
				char	update_approve = 'N';

				drawScreensHeaders("Update Client Screen");
				
				do
				{

					ID_ToUpdate = InputValidator::readString("\n\t\t\t\t\t\tPlease enter account ID number inorder to Update: ");
					if (!(clsBankClient::isClientExist(ID_ToUpdate)))
						printf("\n\t\t\t\t\t\tNo Client is Exist with this ID Number;\n");

				}					while (!(clsBankClient::isClientExist(ID_ToUpdate)));
				

				clsBankClient	ClientToUpdate = clsBankClient::Find(ID_ToUpdate);
				PrintClient(ClientToUpdate);
				update_approve = InputValidator::readChr("\n\n\t\t\t\t\t\tAre you sure do you want to Update the Client? (Y/N): ");
				if (std::toupper(update_approve) != 'Y')
					return ;


				_ReadUpdatingClientInfo(ClientToUpdate);

				clsBankClient::e_save_result	Saving;
				Saving = ClientToUpdate.Save();
				_PrintUpdateResult(Saving);

				

				// if(ClientToUpdate.deleteClientObj())
				// {
				// 	std::cout << "\nClient is Deleted Succesfully.";
				// 	PrintClient(ClientToUpdate);
				// }
				// else
				// 	std::cout << "\nClient isn't Deleted.";


			}


	
};




# endif