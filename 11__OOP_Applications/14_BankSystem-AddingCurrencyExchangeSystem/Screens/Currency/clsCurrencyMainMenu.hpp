#pragma once

#ifndef CLSCURRENCYMAINMENU_CPP
# define CLSCURRENCYMAINMENU_CPP


# include <cstdio>
# include "../clsScreen.hpp"
# include "clsCurrencySuperScreen.hpp"
# include "clsShowAllUsersScreen.hpp"
# include "clsAddNewUserScreen.hpp"
# include "clsDeleteUserScreen.hpp"
# include "clsUpdateUserInfoScreen.hpp"
# include "clsFindUserScreen.hpp"
# include "clsShowAllCurrenciesScreen.hpp"
# include "clsFindCurrencyScreen.hpp"
# include "clsUpdateCurrencyScreen.hpp"
# include "clsCurrencyCalculatorScreen.hpp"

class clsCurrencyMainMenu : protected clsCurrencySuperScreen
{
public:

        static short    ShowCurrencyMenuScreen()
        {

			short perform = 0;
			system("clear");
		
			drawScreensHeaders("-- Currency Main Menu --", "Currencies System");

			_DisplayCurrencySystemOptions();

			perform = _PerformCurrencyMenuOption(  (E_CURRENCY_MENU_OPTIONS)\
												InputValidator::readRangedNumberShort\
												(1, 5, 
												"\t\t\t\t\t\t\tPlease enter a number between (1) and (5):  "));
			if (perform == -44)
				return -44;

			else if (perform == (short)E_CURRENCY_MENU_OPTIONS::MAIN_MENU_BACK)
				return ((short)E_CURRENCY_MENU_OPTIONS::MAIN_MENU_BACK);

			return 0;
        }


private:

			static void	_DisplayCurrencySystemOptions() {
				int menuWidth = 45;  // Width of the menu items block
				int totalWidth = 80; // Total terminal width
				int padding = (totalWidth - menuWidth) / 2;  // Padding for centering the menu block

				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "===========================================" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[1] List Currencies." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[2] Find Currency." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[3] Update a Currency Rate." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[4] Currency Calculator." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[5] Back to Main Menu." << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding - 3) << "" << "=================================================" << std::endl;
			}


            static short    _ShowAllCurrenciesScreen()
            {
				// std::cout << "\nShow All Currencies Screen Will be here...\n";
				clsShowAllCurrenciesScreen::ShowAllCurrenciesScreen(); 
				return 0;
            }


			static short	_FindCurrencyScreen()
            {
				// std::cout << "\nFind Currency Screen Will be here...\n";
				// clsAddNewUserScreen::ShowAddNewUserScreen();
				clsFindCurrencyScreen::ShowFindCurrencyScreen();
				return 0;

            }
   

			static short    _UpdateRateScreen()
            {
				// std::cout << "\nUpdate Rate  Screen Will be here...\n";
				clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
				return 0;
            }
			


			static short	_CurrencyCalculatorScreen()
			{
				// std::cout << "\nCurrency Calculator Screen Will be here...\n";
				if ((clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen()))
					return 1;

				return 0;
			}



            enum  class E_CURRENCY_MENU_OPTIONS
            {
				        LIST_ALL = 1,		FIND = 2,
						UPDATE_RATE = 3 ,	CURRENCY_CALCULATOR = 4,
						MAIN_MENU_BACK = 5
            };


  			static void	_PressToBackToCurrencyMenuScreen()
			{
				std::cout << "\n" << CoreUtilities::Tabs(7) << "Press any key to go back to Currency Main Screen ...\n";

				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();

				system("clear");
				ShowCurrencyMenuScreen();
			}



           static short	_PerformCurrencyMenuOption(E_CURRENCY_MENU_OPTIONS Option)
			{

				system("clear");
				
				switch (Option)
				{
					case E_CURRENCY_MENU_OPTIONS::LIST_ALL:
						_ShowAllCurrenciesScreen();
						break;

					case E_CURRENCY_MENU_OPTIONS::FIND :
						_FindCurrencyScreen();
						break;
						
					case E_CURRENCY_MENU_OPTIONS::UPDATE_RATE :
						if (_UpdateRateScreen() == -44)
							return -44;
						break;
					
					
					case E_CURRENCY_MENU_OPTIONS::CURRENCY_CALCULATOR :
					 	if(!(_CurrencyCalculatorScreen()))
							break;
						else 
							ShowCurrencyMenuScreen();

					case E_CURRENCY_MENU_OPTIONS::MAIN_MENU_BACK :
					 	return (short)E_CURRENCY_MENU_OPTIONS::MAIN_MENU_BACK;
				} 
				
				_PressToBackToCurrencyMenuScreen();
				return 0;
            }



};


#endif