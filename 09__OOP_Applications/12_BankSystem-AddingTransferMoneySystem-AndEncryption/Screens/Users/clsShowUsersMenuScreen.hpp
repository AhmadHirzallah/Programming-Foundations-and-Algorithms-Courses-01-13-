#pragma once

#ifndef CLSSHOWUSERSMENUSCREEN_HPP
# define CLSSHOWUSERSMENUSCREEN_HPP


# include <cstdio>
# include "../clsScreen.hpp"
# include "clsUsersSuperScreen.hpp"
# include "clsShowAllUsersScreen.hpp"
# include "clsAddNewUserScreen.hpp"
# include "clsDeleteUserScreen.hpp"
# include "clsUpdateUserInfoScreen.hpp"
# include "clsFindUserScreen.hpp"


class clsShowUsersMenuScreen : protected clsUsersSuperScreen
{
public:

        static short    ShowUsersMenuScreen()
        {
            system("clear");
           
            drawScreensHeaders("Users Management Screen", "Users Menu");

            _DisplayUsersManagementOptions();

            if (_PerformUsersManagementMenuOption(  (E_USERS_MANAG_MENU_OPTIONS)\
                                                InputValidator::readRangedNumberShort\
												(1, 6, 
												"\t\t\t\t\t\t\tPlease enter a number between (1) and (6):  ")) == -44)
			{
				return -44;
			}
			return 0;
        }


private:

			static void	_DisplayUsersManagementOptions() {
				int menuWidth = 45;  // Width of the menu items block
				int totalWidth = 80; // Total terminal width
				int padding = (totalWidth - menuWidth) / 2;  // Padding for centering the menu block

				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "===========================================" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[1] Show User List." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[2] Add New User." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[3] Delete User." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[4] Update User Info." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[5] Find User." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[6] Back to Main Menu." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding - 3) << "" << "=================================================" << std::endl;
			}


            static void    _ShowAllUsersScreen()
            {
				clsShowAllUsersScreen::ShowUsersListScreen();
				// std::cout << "\nShow All Users Screen Will be here...\n";
            }


			static void    _AddNewUserScreen()
            {
				// std::cout << "\nAdd User Screen Will be here...\n";
				clsAddNewUserScreen::ShowAddNewUserScreen();

            }
   

			static short    _DeleteUserScreen()
            {
				if (clsDeleteUserScreen::ShowDeleteUserScreen() == -44)
					return -44;
				// std::cout << "\nDelete User Screen Will be here...\n";
				return 0;
            }


			static void    _UpdateUserInfoScreen()
            {
				clsUpdateUserInfoScreen::ShowUpdateUserScreen();
				// std::cout << "\nUpdate User Screen Will be here...\n";
            }


			static void    _FindUserScreen()
            {
				clsFindUserScreen::ShowFindUserScreen();
				// std::cout << "\nFind User Screen Will be here...\n";
				return ;
            }
							


            enum class E_USERS_MANAG_MENU_OPTIONS
            {
				LIST_USERS = 1,	ADD_NEW_USER = 2,	DELETE_USER = 3,	UPDATE_USER = 4,
				FIND_USER = 5,	MAIN_MENU_BACK = 6
            };


			static void	_PressToBackToUsersMenuScreen()
			{
				std::cout << "\n" << CoreUtilities::Tabs(7) << "Press any key to go back to Users Management Screen ...\n";

				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();

				system("clear");
				ShowUsersMenuScreen();
			}


           static short	_PerformUsersManagementMenuOption(E_USERS_MANAG_MENU_OPTIONS Option)
			{

				system("clear");
				
				switch (Option)
				{
					case E_USERS_MANAG_MENU_OPTIONS::LIST_USERS:
						_ShowAllUsersScreen();
						break;

					case E_USERS_MANAG_MENU_OPTIONS::ADD_NEW_USER:
						_AddNewUserScreen();
						break;
						
					case E_USERS_MANAG_MENU_OPTIONS::DELETE_USER:
						if (_DeleteUserScreen() == -44)
							return -44;
						break;
					
					case E_USERS_MANAG_MENU_OPTIONS::UPDATE_USER:
						_UpdateUserInfoScreen();
						break;

					case E_USERS_MANAG_MENU_OPTIONS::FIND_USER :
						_FindUserScreen();
						break;

					case E_USERS_MANAG_MENU_OPTIONS::MAIN_MENU_BACK:
                        return 0;
				} 

				_PressToBackToUsersMenuScreen();
				return 0;
            }



};


#endif