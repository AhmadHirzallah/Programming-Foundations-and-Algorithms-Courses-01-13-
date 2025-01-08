
#ifndef CLSCURRENCYCALCULATORSCREEN_HPP 
# define CLSCURRENCYCALCULATORSCREEN_HPP  

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsCurrency.hpp"
# include "clsCurrencySuperScreen.hpp"
# include <cstdio>

class clsCurrencyCalculatorScreen : protected clsCurrencySuperScreen
{

private:


        static std::string     _ReadCurrencies(std::string Message)
        {
            char    _procceed_fl;

            std::string _CurrencyIdentifier = InputValidator::readString(Message);

            while (!(clsCurrency::isExist(_CurrencyIdentifier)))
            {    
                _CurrencyIdentifier = InputValidator::readString("There is (No) Exist Currency with this Currency Code or Country.\n\nPlease enter a Valid Currency's (Code/Country) or press (q) to quit:  ");
                _procceed_fl = _CurrencyIdentifier[0];
                if (tolower(_procceed_fl) == 'q')
                    return ("q");                 //Quit using (q)
            }

            return (_CurrencyIdentifier);
        }


public:

    static short   ShowCurrencyCalculatorScreen()
    {
        char    again = 'y';



        while (tolower(again) == 'y')
        {
            system("clear");
            again = 'n';
            drawScreensHeaders("Currency Calculator Screen");

            std::string currencyIdentifier1;
            std::string currencyIdentifier2;

            currencyIdentifier1 = _ReadCurrencies("\n\nPlease enter the Currency's (Code) or (Country) inorder to (Convert From):  ");
            if (currencyIdentifier1 == "q") //Quit
                return 1;
            clsCurrency currencyFrom = clsCurrency::Find(currencyIdentifier1, clsCurrency::E_FIND::COUNTRY_AND_CODE);


            currencyIdentifier2 = _ReadCurrencies("\n\nPlease enter the Currency's (Code) or (Country) inorder to (Convert To):  ");
            if (currencyIdentifier2 == "q") //Quit
                return 1;
            clsCurrency currencyTo = clsCurrency::Find(currencyIdentifier2, clsCurrency::E_FIND::COUNTRY_AND_CODE);


            double amount = InputValidator::readRangedNumberDouble(0, std::numeric_limits<double>::max(), "\n\nEnter Amount to Exchange:  ");

            std::cout << "\n\n";
            std::cout << CoreUtilities::Tabs(7) <<"Convert FROM:\n";
            printCurrencyInfoCard(currencyFrom);
            
            
            std::cout << "\n\n";
            std::cout << CoreUtilities::Tabs(7) << "Convert To:\n";
            printCurrencyInfoCard(currencyTo);


            printf("%s_________________________________________________", CoreUtilities::Tabs(6).c_str());

            printf("\n\n%sTo USD:\n%s%.4f (%s) = %.4f ($)\n\n", 
            CoreUtilities::Tabs(7).c_str(),
            CoreUtilities::Tabs(7).c_str(),
            amount, currencyFrom.Code().c_str(),
            currencyFrom.rateToUSD(amount));


            if (currencyTo.Code() == StringUtils::toUpperAllString("USD")) 
            {
                again = InputValidator::readChr("\n\nDo You Want to Perform More Currency Exchanges? [To do Enter (Y)]:  ");
                if (tolower(again) == 'y')
                    continue;
                return 1;

            }

            printf("\n\n%sTo %s:\n%s%.4f (%s) = %.4f (%s)\n\n", 
            CoreUtilities::Tabs(7).c_str(),
            currencyTo.Code().c_str(),
            CoreUtilities::Tabs(7).c_str(),
            amount, 
            currencyFrom.Code().c_str(),
            currencyFrom.currencyConverter(amount, currencyTo.Code()), 
            currencyTo.Code().c_str());

            printf("%s_________________________________________________", CoreUtilities::Tabs(6).c_str());
            
            again = InputValidator::readChr("\n\nDo You Want to Perform More Currency Exchanges? [To do Enter (Y)]:  ");
        }

        if ((tolower(again) != 'y'))
            return 1;

        return (0);
    }    

};


# endif