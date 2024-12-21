#pragma once

#ifndef	CLSMAINSCREEN_HPP
# define CLSMAINSCREEN_HPP

// # include "../../Include/"
# include <iomanip>
# include "../../Core/clsPerson.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../clsScreen.hpp"
# include "clsShowAllClientsScreen.hpp"
# include "clsAddNewClientScreen.hpp"
# include "clsDeleteClientScreen.hpp"
# include "clsUpdateClientInfoScreen.hpp"
# include "clsFindClientScreen.hpp"
# include "clsTransactionsMenuScreen.hpp"

class	clsMainScreen : public clsScreen
{

public:

			static void	showMainMenu()
			{
				system("clear");

				drawScreensHeaders("Main Menu");

				_DisplayMainMenuOptions();

				_PerformMainMenuOption((E_MAIN_MENU_OPTIONS) InputValidator::readRangedNumberShort\
																		(1, 8, 
																		"\t\t\t\t\t\t\tPlease enter a number between (1) and (8):  "));
			}



private:

			enum class	E_MAIN_MENU_OPTIONS	
			{
				LIST_CLIENTS = 1,	ADD_NEW_CLIENT = 2,	DELETE_CLIENT = 3,	UPDATE_CLIENT = 4,
				FIND_CLIENT = 5,	TRANSACTIONS_SYSTEM = 6,	USERS_SYSTEM = 7,		EXIT = 8,
				LOGOUT
			};


			static void	_DisplayMainMenuOptions()
			{
				int menuWidth = 45;  // Width of the menu items block
				int totalWidth = 80; // Total terminal width
				int padding = (totalWidth - menuWidth) / 2;  // Padding for centering the menu block

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
			}


			static void	_ShowAllClientsScreen()
			{
				clsShowAllClientsScreen::ShowClientsList();
			}


			static void	_AddNewClientScreen()
			{
				clsAddNewClientScreen::AddNewClient();
			}


			static void	_DeleteClientScreen()
			{
				clsDeleteClientScreen::DeleteClient();
			}


			static void	_UpdateClientInfoScreen()
			{
				clsUpdateClientInfoScreen::UpdateClient();
			}


			static void	_FindClientScreen()
			{
				clsFindClientScreen::FindClient();
			}


			static void	_ShowTransactionsMenuScreen()
			{
				clsTransactionsMenuScreen::showTransactionsMenu();
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

				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();

				system("clear");
				showMainMenu();
			}


			static void	_PerformMainMenuOption(E_MAIN_MENU_OPTIONS Option)
			{

				system("clear");
				
				switch (Option)
				{
					case E_MAIN_MENU_OPTIONS::LIST_CLIENTS :
						_ShowAllClientsScreen();
						break;

					case E_MAIN_MENU_OPTIONS::ADD_NEW_CLIENT:
						_AddNewClientScreen();
						break;
						
					case E_MAIN_MENU_OPTIONS::DELETE_CLIENT:
						_DeleteClientScreen();
						break;
					
					case E_MAIN_MENU_OPTIONS::UPDATE_CLIENT :
						_UpdateClientInfoScreen();
						break;

					case E_MAIN_MENU_OPTIONS::FIND_CLIENT :
						_FindClientScreen();
						break;

					case E_MAIN_MENU_OPTIONS::TRANSACTIONS_SYSTEM :
						_ShowTransactionsMenuScreen();
						break;

					case E_MAIN_MENU_OPTIONS::USERS_SYSTEM :
						_ShowUsersManagementMenuScreen();
						break;

					case E_MAIN_MENU_OPTIONS::EXIT :
						_ShowEndScreen();
						return ;
				}

				if (Option == E_MAIN_MENU_OPTIONS::TRANSACTIONS_SYSTEM) 
					showMainMenu();		// Because you press 4 in transaction (back to main menu) then you should back without pressing another key!!!!
				else 
					_GoBackToMainMenue();	//	Press any key to back to main menu.
			}




};



#endif