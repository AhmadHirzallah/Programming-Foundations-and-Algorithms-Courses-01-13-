#pragma once

#ifndef	CLSMAINSCREEN_HPP
# define CLSMAINSCREEN_HPP

// # include "../../Include/"
# include <iomanip>
# include "../Core/clsPerson.hpp"
# include "../Include/CoreUtilities.hpp"
# include "../Include/InputValidator.hpp"
# include "clsScreen.hpp"
# include "Clients/clsShowAllClientsScreen.hpp"
# include "Clients/clsAddNewClientScreen.hpp"
# include "Clients/clsDeleteClientScreen.hpp"
# include "Clients/clsUpdateClientInfoScreen.hpp"
# include "Clients/clsFindClientScreen.hpp"
# include "Clients/clsTransactionsMenuScreen.hpp"

# include "Clients/clsClientsSuperScreen.hpp"

# include "Users/clsShowUsersMenuScreen.hpp"
# include "../Include/Global.hpp"

# include "clsLoginHistoryRegScreen.hpp"

#include "Currency/clsCurrencyMainMenu.hpp"

class	clsMainScreen : protected clsClientsSuperScreen
{

public:

			static void	showMainMenu()
			{
				system("clear");

				drawScreensHeaders("Main Menu");

				_DisplayMainMenuOptions();

				_PerformMainMenuOption((E_MAIN_MENU_OPTIONS) InputValidator::readRangedNumberShort\
																		(1, 10, 
																		"\t\t\t\t\t\t\tPlease enter a number between (1) and (10):  "));
			}



private:

			enum class	E_MAIN_MENU_OPTIONS	
			{
				LIST_CLIENTS = 1,	ADD_NEW_CLIENT = 2,	DELETE_CLIENT = 3,	UPDATE_CLIENT = 4,
				FIND_CLIENT = 5,	TRANSACTIONS_SYSTEM = 6,	USERS_SYSTEM = 7,	LOGIN_HISTORY_REGISTERING = 8,
				CURRENCY_EXCHANGE = 9	,LOGOUT = 10
			};


			static void	_DisplayMainMenuOptions()
			{
				int menuWidth = 45;  // Width of the menu items block
				int totalWidth = 80; // Total terminal width
				int padding = (totalWidth - menuWidth) / 2;  // Padding for centering the menu block

				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "===========================================" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[1]  Show Clients List." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[2]  Add New Client." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[3]  Delete Client." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[4]  Update Client Info." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[5]  Find Client." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[6]  Transactions." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[7]  Manage Users." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[8]  Login History Register." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[9]  Currency Exchange System." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[10] Logout." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding - 3) << "" << "=================================================" << std::endl;
			}


			static void	_ShowAllClientsScreen()
			{
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_LIST_CLIENTS))
					clsShowAllClientsScreen::ShowClientsListScreen();
			}


			static void	_AddNewClientScreen()
			{
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_ADD_NEW_CLIENTS))
					clsAddNewClientScreen::ShowAddNewClientScreen();
			}


			static void	_DeleteClientScreen()
			{
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_DELETE_CLIENTS))
					clsDeleteClientScreen::ShowDeleteClientScreen();
			}


			static void	_UpdateClientInfoScreen()
			{
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_UPDATE_CLIENTS))
					clsUpdateClientInfoScreen::ShowUpdateClientScreen();
			}


			static void	_FindClientScreen()
			{
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_FIND_CLIENTS))
					clsFindClientScreen::ShowFindClientScreen();
			}


			static void	_ShowTransactionsMenuScreen()
			{
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_MANAGE_TRANSACTIONS))
					clsTransactionsMenuScreen::ShowTransactionsMenuScreen();

				else			//	Press any key to back to main menu. (Because it will back immidietly without pressing any key)
				{
					std::cout << "\n" << CoreUtilities::Tabs(7) << "Press any key to go back to Main Menu...\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin.get();
				}
					
			}


			static short	_ShowUsersManagementMenuScreen()
			{

				// std::cout << "\nManage Users Menu Screen Will be here...\n";
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_MANAGE_USERS))
				{
					if (clsShowUsersMenuScreen::ShowUsersMenuScreen() == -44)
						return -44;			//		 The current user is deleted flag; Logout!

					return 0;
				}

				else			//	Press any key to back to main menu. (Because it will back immidietly without pressing any key)
				{
					std::cout << "\n" << CoreUtilities::Tabs(7) << "Press any key to go back to Main Menu...\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin.get();
					return 0;
				}

			}


			static void	_ShowLoginHistoryRegisterScreen()
			{
				//  std::cout << "\nLogin Register Screen Will be here...\n";
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_SHOW_LOGIN_REG_HISTORY))
					clsLoginHistoryRegScreen::ShowLoginHistoryRegisterScreen();

			}


			static void	_ShowCurrencyExchangeScreen()
			{
				//  std::cout << "\nCurrency Exchange System  Will be here...\n";
				if(!CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS::PER_SHOW_CURRENCY_EXCHANGE_SYSTEM))
					clsCurrencyMainMenu::ShowCurrencyMenuScreen();
			}

						


			static void	_Logout()
			{
				g_ActiveUser = clsBankUser::Find("", "");
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
						if(_ShowUsersManagementMenuScreen() == -44)	//Deleted Current User Flag
							return;
						break;

					case E_MAIN_MENU_OPTIONS::LOGIN_HISTORY_REGISTERING :
						_ShowLoginHistoryRegisterScreen();
						break;

					case E_MAIN_MENU_OPTIONS::CURRENCY_EXCHANGE :
						_ShowCurrencyExchangeScreen();
						break;

					case E_MAIN_MENU_OPTIONS::LOGOUT :
						_Logout();
						return ;
				}

				if ((Option == E_MAIN_MENU_OPTIONS::TRANSACTIONS_SYSTEM 
					|| Option ==  E_MAIN_MENU_OPTIONS::USERS_SYSTEM)
					|| Option ==  E_MAIN_MENU_OPTIONS::CURRENCY_EXCHANGE)
					showMainMenu();		// Because you press 4 in transaction (back to main menu) then you should back (without prompting from user again) without pressing another key!!!!
				else 
					_GoBackToMainMenue();	//	Press any key to back to main menu.
			}




};



#endif