#pragma once

#ifndef	CLSMAINSCREEN_HPP
# define CLSMAINSCREEN_HPP

# include <iomanip>
# include "../../Core/clsPerson.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../clsScreen.hpp"


class	clsMainScreen : public clsScreen
{

private:

			enum	e_main_menu_options
			{
				LIST_CLIENTS = 1,	ADD_NEW_CLIENT = 2,	DELETE_CLIENT = 3,	UPDATE_CLIENT = 4,
				FIND_CLIENT = 5,	TRANSACTIONS_SYSTEM = 6,	USERS_SYSTEM = 7,		EXIT = 8,
				LOGOUT
			};


			static void	_PrintMenuOptions()
			{
				int menuWidth = 45;  // Width of the menu items block
				int totalWidth = 80; // Total terminal width
				int padding = (totalWidth - menuWidth) / 2;  // Padding for centering the menu block

				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "===========================================" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t\t  Main Menu" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "===========================================" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[1] Show Client List." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[2] Add New Client." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[3] Delete Client." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[4] Update Client Info." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[5] Find Client." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[6] Transactions." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[7] Manage Users." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[8] Exit." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding - 3) << "" << "=================================================" << std::endl;
				std::cout << "\n" << CoreUtilities::Tabs(7) << "Enter a number between (1) and (8): ";
			}


			static void	_ShowAllClientsScreen()
			{
				std::cout << "\nAll Client List Screen Will be here...\n";
			}


			static void	_AddNewClientScreen()
			{
				std::cout << "\nAdd new Client Screen Will be here...\n";
			}


			static void	_DeleteClientScreen()
			{
				std::cout << "\nDelete Client Screen Will be here...\n";
			}


			static void	_UpdateClientInfoScreen()
			{
				std::cout << "\nUpdate CLient Screen Will be here...\n";
			}


			static void	_FindClientScreen()
			{
				std::cout << "\nFind Client Screen Will be here...\n";
			}


			static void	_ShowTransactionsMenuScreen()
			{
				std::cout << "\nShow Transaction Screen Will be here...\n";
			}


			static void	_ShowUsersManagementMenuScreen()
			{
				std::cout << "\nManage Users Menu Screen Will be here...\n";
			}


			static void	_ShowEndScreen()
			{
				std::cout << "\nEnd Screen  Screen Will be here...\n";
			}


			static void _GoBackToMainMenue()
			{
				std::cout << "\n" << CoreUtilities::Tabs(7) << "Press any key to go back to Main Menu...\n";
				std::cin.ignore();	// Waits for the user to press any key
				std::cin.get();
				showMainMenu();
			}


			static void	_PerformMainMenuOption(e_main_menu_options option_e)
			{
				switch (option_e)
				{
					case e_main_menu_options::LIST_CLIENTS :
						system("clear");
						_ShowAllClientsScreen();
						_GoBackToMainMenue();
						break;

					case e_main_menu_options::ADD_NEW_CLIENT:
						system("clear");
						_AddNewClientScreen();
						_GoBackToMainMenue();
						break;
						
					case e_main_menu_options::DELETE_CLIENT:
						system("clear");
						_DeleteClientScreen();
						_GoBackToMainMenue();
						break;
					
					case e_main_menu_options::UPDATE_CLIENT :
						system("clear");
						_UpdateClientInfoScreen();
						_GoBackToMainMenue();
						break;

					case e_main_menu_options::FIND_CLIENT :
						system("clear");
						_FindClientScreen();
						_GoBackToMainMenue();
						break;

					case e_main_menu_options::TRANSACTIONS_SYSTEM :
						system("clear");
						_ShowTransactionsMenuScreen();
						_GoBackToMainMenue();
						break;

					case e_main_menu_options::USERS_SYSTEM :
						system("clear");
						_ShowUsersManagementMenuScreen();
						_GoBackToMainMenue();
						break;

					case e_main_menu_options::EXIT :
						system("clear");
						_ShowEndScreen();
						break;
					
				}
			}
public:

			static void	showMainMenu()
			{
				system("clear");

				drawScreensHeaders("Main Menu");

				_PrintMenuOptions();

				_PerformMainMenuOption((e_main_menu_options) InputValidator::readRangedNumberShort\
																		(1, 8, "Please enter a number between (0) and (8) again: "));
			}

};



#endif