#pragma once

#ifndef CLSUSERSSUPERSCREEN_HPP
# define	CLSUSERSSUPERSCREEN_HPP

# include <iostream>
# include "../clsScreen.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../../Core/clsBankUser.hpp"

class	clsUsersSuperScreen : protected clsScreen
{

private:
		
		//		//		//

protected:


			static int	readUserPermissions()
			{

				int	permissions;
				char	answer;

				answer = 'n';
				permissions = 0;


				printf("\n\n(Answer with (Y) to give the specified Permission)\n");


				printf("\n\nDo you want to give a Full Access?  ");
				std::cin >> answer;
				if (toupper(answer) == 'Y')
					return (-1);


				printf("\n\nDo you want to give Access to: \
						\n\n\nShow List of All Clients:   ");

				std::cin >> answer;
				if (toupper(answer) == 'Y')
					permissions += clsBankUser::E_USERS_PERMISSIONS::PER_LIST_CLIENTS;


				printf("\n\nAdd New Client:   ");
				std::cin >> answer;
				if (toupper(answer) == 'Y')
					permissions += clsBankUser::E_USERS_PERMISSIONS::PER_ADD_NEW_CLIENTS;


				printf("\n\nDelete a Client:   ");
				std::cin >> answer;
				if (toupper(answer) == 'Y')
					permissions += clsBankUser::E_USERS_PERMISSIONS::PER_DELETE_CLIENTS;


				printf("\n\nUpdate a Client:   ");
				std::cin >> answer;
				if (toupper(answer) == 'Y')
					permissions += clsBankUser::E_USERS_PERMISSIONS::PER_UPDATE_CLIENTS;


				printf("\n\nFind a Client:   ");
				std::cin >> answer;
				if (toupper(answer) == 'Y')
					permissions += clsBankUser::E_USERS_PERMISSIONS::PER_FIND_CLIENTS;


				printf("\n\nManage Transactions:   ");
				std::cin >> answer;
				if (toupper(answer) == 'Y')
					permissions += clsBankUser::E_USERS_PERMISSIONS::PER_MANAGE_TRANSACTIONS;


				printf("\n\nManage Users:   ");
				std::cin >> answer;
				if (toupper(answer) == 'Y')
					permissions += clsBankUser::E_USERS_PERMISSIONS::PER_MANAGE_USERS;


				printf("\n\nShow List of Login Registers History:   ");
				std::cin >> answer;
				if (toupper(answer) == 'Y')
					permissions += clsBankUser::E_USERS_PERMISSIONS::PER_SHOW_LOGIN_REG_HISTORY;

				return (permissions);
			}



							// Used in: clsAddNewUser
			static short   inputReadingUserInfo(clsBankUser &User)
			{
				char    proceed_fl = 'n';

				std::cout <<"\n\nPlease enter (Y) if you want to proceed the process:  ";
				std::cin >> proceed_fl;
				if (tolower(proceed_fl) != 'y')
					return (1);                     //      Stop Input return

				User.setFirstname(InputValidator::readString("\n\nPlease enter First Name: "));

				User.setLastname(InputValidator::readString("\nPlease enter Last Name: "));

				User.setEmail(InputValidator::readString("\nPlease enter Email: "));

				User.setPhoneNbr(InputValidator::readString("\nPlease enter Phone Number: "));

				User.SetPassword(InputValidator::readString("\nPlease enter Password: "));

				// Set Permissions
				User.SetPermissons(readUserPermissions());

				return (0);
			}


			static void    printUserInfoCard(clsBankUser &User)
			{
				int cardWidth = 45;  // Width of the card block
				int totalWidth = 160; // Total terminal width
				int padding = (totalWidth - cardWidth) / 2;  // Padding for centering the card block

				std::cout << "\n\n";
				std::cout << std::setw(padding) << std::right << "" << "User Card:" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "First Name   : " << User.Firstname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Last Name    : " << User.Lastname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Full Name    : " << User.Fullname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Email        : " << User.Email() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Phone        : " << User.PhoneNbr() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "UserName     : " << User.Username() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Password     : " << User.Password() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Permissions  : " << User.Permissions() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::endl;
			}







};



#endif