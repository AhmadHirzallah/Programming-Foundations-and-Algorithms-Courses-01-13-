
#pragma once

#ifndef CLSTRANSACTIONSMENUSCREEN_HPP
# define CLSTRANSACTIONSMENUSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"
# include "../Transactions/clsDepositScreen.hpp"
# include "../Transactions/clsWithDrawScreen.hpp"
# include "../Transactions/clsShowTotalBalances.hpp"
# include "../Transactions/clsTransferScreen.hpp"
# include "clsClientsSuperScreen.hpp"
# include "clsTransferHistoryRegisterScreen.hpp"

class clsTransactionsMenuScreen : protected clsClientsSuperScreen 
{
private:

    enum class  EN_TRANSACTIONS_MENU_CHOICES
    {
        DEPOSIT = 1,    // ايداع
        WITHDRAW,   // سحب
        TOTAL_BALANCES,
        TRANSFER,
        TRANSFER_HIRSTORY_REGISTERING,
        BACK_TO_MAIN_MENU
    };

    static void    _DisplayMainMenuOptions()
    {
                int menuWidth = 45;  // Width of the menu items block
				int totalWidth = 80; // Total terminal width
				int padding = (totalWidth - menuWidth) / 2;  // Padding for centering the menu block

				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "===========================================" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[1] Deposit" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[2] Withdraw" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[3] Show Total Balances" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[4] Perform a Transfer" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[5] Transfer History Register" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding) << "" << "\t[6] Back to Main Menu" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << std::setw(padding - 3) << "" << "=================================================" << std::endl;
    }


    //      Screens Implementations:

    static void _showDepositScreen()
    {
        clsDepositScreen::showDepositScreen();
    }

    
    static void _showWithdrawScreen()
    {
        clsWithDrawScreen::showWithDrawScreen();
    }


    static void _showTotalBalancesScreen()
    {
        clsShowTotalBalances::ShowTotalBalancesOfClientsScreen();
    }


    static short _showTransferScreen()
    {
        // std::cout << "\nTransfer Screen Will Be Here...\n";
        if(!(clsTransferScreen::showTransferScreen()))
            return 0;
        return 1;
    }
        
    static void _showTransferHistoryRegScreen()
    {
        // std::cout << "\nTransfer History Screen Will Be Here...\n";
        clsTransferHistoryRegisterScreen::ShowTransferHistoryRegisterScreen();

    }

    

    static void _goBackToTransactionsMenuScreen()
    {
        std::cout << "\n" << CoreUtilities::Tabs(7) << "Press any key to go back to Transactions Menu ...\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();

        system("clear");

        ShowTransactionsMenuScreen();
    }

	static void	_PerformTransactionsMenuOption(EN_TRANSACTIONS_MENU_CHOICES Option)
    {
		system("clear");

        if (Option == EN_TRANSACTIONS_MENU_CHOICES::DEPOSIT)
            _showDepositScreen();
        else if (Option == EN_TRANSACTIONS_MENU_CHOICES::WITHDRAW)
            _showWithdrawScreen();
        else if (Option == EN_TRANSACTIONS_MENU_CHOICES::TOTAL_BALANCES)
            _showTotalBalancesScreen();
        else if (Option == EN_TRANSACTIONS_MENU_CHOICES::TRANSFER)
            _showTransferScreen();
        else if (Option == EN_TRANSACTIONS_MENU_CHOICES::TRANSFER_HIRSTORY_REGISTERING)
            _showTransferHistoryRegScreen();
        else if (Option == EN_TRANSACTIONS_MENU_CHOICES::BACK_TO_MAIN_MENU)
            return ;

        _goBackToTransactionsMenuScreen();
    }



public:

    static void ShowTransactionsMenuScreen()
    {
        system("clear");
		drawScreensHeaders("Transaction Main Menu");
		_DisplayMainMenuOptions();
        _PerformTransactionsMenuOption((EN_TRANSACTIONS_MENU_CHOICES) InputValidator::readRangedNumberShort(1, 6,
                                                                         "\t\t\t\t\t\t\tPlease enter a number between (1) and (6):  "));
    }   

};





# endif