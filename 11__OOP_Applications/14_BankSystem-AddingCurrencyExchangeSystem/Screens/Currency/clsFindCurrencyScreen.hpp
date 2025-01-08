
#ifndef CLSFINDCURRENCYSCREEN_HPP
# define  CLSFINDCURRENCYSCREEN_HPP 

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsCurrency.hpp"
# include "clsCurrencySuperScreen.hpp"

class clsFindCurrencyScreen : protected clsCurrencySuperScreen 
{

private:


public:

    static short   ShowFindCurrencyScreen()
    {
        std::string Currencyname;
        char    procceed_fl;

        drawScreensHeaders("Find Currency Screen");

        Currencyname = InputValidator::readString("\n\nPlease enter the Currency's (Code) or (Country) inorder to Find:  ");

        while (!(clsCurrency::isExist(Currencyname)))
        {    
            Currencyname = InputValidator::readString("There is (No) Exist Currency with this (Currency Code) or (Country).\n\nPlease enter a Valid Currency's (Code/Country) or press (q) to quit:  ");
            procceed_fl = Currencyname[0];
            if (tolower(procceed_fl) == 'q')
                return (1);                 //Quit using (q)
        }

        clsCurrency Currency = clsCurrency::Find(Currencyname, clsCurrency::E_FIND::COUNTRY_AND_CODE);

        if (Currency.isExist())
            std::cout << "\n\nCurrency Found. :)\n\n";
        else
            std::cout << "\n\nCurrency isn't Found. :(\n\n";

        printCurrencyInfoCard(Currency);

        return (0);
    }    

};


# endif