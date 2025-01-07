#pragma once

#ifndef CLSCURRENCYSUPERSCREEN_CPP 
# define CLSCURRENCYSUPERSCREEN_CPP 	

# include <iostream>
# include "../clsScreen.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../../Core/clsCurrency.hpp"




class clsCurrencySuperScreen : protected clsScreen
{

protected:
		
			static void    printCurrencyInfoCard(clsCurrency &Currency)
			{
				int cardWidth = 45;  // Width of the card block
				int totalWidth = 160; // Total terminal width
				int padding = (totalWidth - cardWidth) / 2;  // Padding for centering the card block

				std::cout << "\n\n";
				std::cout << std::setw(padding) << std::right << "" << "Currency Card:" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Country Name : " << Currency.Country() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Code         : " << Currency.Code() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Name         : " << Currency.Name() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Rate(1$)     : " << Currency.Rate() << std::endl;
				std::cout << std::endl;
			}

private:






};



#endif