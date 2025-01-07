
#ifndef CLSUPDATECURRENCYSCREEN_HPP
# define  CLSUPDATECURRENCYSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsCurrency.hpp"
# include "clsCurrencySuperScreen.hpp"

class clsUpdateCurrencyScreen : protected clsCurrencySuperScreen 
{

private:

        static double  _readUpdateRate()
        {
            char    fl;
            double update_rate = 0;

            update_rate = InputValidator::readRangedNumberDouble(0,
                                                             (std::numeric_limits<double>::max()), "Enter New Currency's Rate:  ");

            fl = InputValidator::readChr("\n\nAre you sure you want to proceed Updating the Currency's Rate? (Press N to cancel):  ");
            if ( tolower(fl) == 'n') 
                return -99;

            return update_rate;
        }



public:

    static short   ShowUpdateCurrencyScreen()
    {
        std::string Currencyname;
        char    procceed_fl;

        drawScreensHeaders("Update Currency Screen");

        Currencyname = InputValidator::readString("\n\nPlease enter the Currency's (Code) or (Country) inorder to Update:  ");

        while (!(clsCurrency::isExist(Currencyname)))
        {    
            Currencyname = InputValidator::readString("There is (No) Exist Currency with this (Currency) Code or (Country).\n\nPlease enter a Valid Currency's (Code/Country) or press (q) to quit:  ");
            procceed_fl = Currencyname[0];
            if (tolower(procceed_fl) == 'q')
                return (1);                 //Quit using (q)
        }

        clsCurrency Currency = clsCurrency::Find(Currencyname, clsCurrency::E_FIND::COUNTRY_AND_CODE);

        printCurrencyInfoCard(Currency);

        if (!(Currency.updateRate(_readUpdateRate())))
        {
            std::cout << "\n\nCurrency Rate is Updated Successfully.\n\n";

            printCurrencyInfoCard(Currency);
        }
        else
        {
            std::cout << "Currency Rate Failed to be Updated.\nThe value you entered is forbidden\n\n";

            printCurrencyInfoCard(Currency);
        }



        return (0);
    }    

};


# endif