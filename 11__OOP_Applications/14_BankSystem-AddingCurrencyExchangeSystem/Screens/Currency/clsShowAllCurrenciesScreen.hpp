
#pragma once

#ifndef CLSSHOWALLCURRENCIESSCREEN_HPP 
# define CLSSHOWALLCURRENCIESSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsCurrency.hpp"
# include "clsCurrencySuperScreen.hpp"

class clsShowAllCurrenciesScreen : protected clsCurrencySuperScreen
{

    private:

            static void    _ListOneCurrency(clsCurrency &Currency)
            {
                printf("\n%s| %-30s | %-15s | %-40s | %.5f$ \n", 
                        CoreUtilities::Tabs(3).c_str(),
                        Currency.Country().c_str(),
                        Currency.Code().c_str(),
                        Currency.Name().c_str(),
                        Currency.Rate());
            }
        
    public:


            static short   ShowAllCurrenciesScreen()
            {
                std::vector <clsCurrency> CurrenciesList = clsCurrency::getCurrenciesListVec();
                // std::vector <clsCurrency> CurrenciesList ;        //Test 0 Currencies Display

                std::string subtitle = "(" + std::to_string(CurrenciesList.size()) + ") Currency(s)" ;

                drawScreensHeaders("All Currencies List Screen", subtitle);

                printf("\n%s| %-30s | %-15s | %-40s | %-20s \n", 
                       CoreUtilities::Tabs(3).c_str() ,"Country", "Code", "Name", "Rate (To USD $)");

                printf("\n________________________________________________________________________________________________________________________________________________________\n");
                if (CurrenciesList.size() < 1)
                {
                    std::cout << "\n\n\n\t\t\t\t\t\t\tThere is (No) Currencies Avialable in the System :( :( : (\n\n\n";
                    printf("________________________________________________________________________________________________________________________________________________________\n");
                    printf("________________________________________________________________________________________________________________________________________________________\n\n\n");
                    return (-1);            //      No Currencies Avialable.
                }

                for (clsCurrency &Currency: CurrenciesList)
                    _ListOneCurrency(Currency);

                printf("________________________________________________________________________________________________________________________________________________________\n");
                printf("________________________________________________________________________________________________________________________________________________________\n\n\n");
                return (0);
            }

};


# endif


/*

                printf("\n\t\t\t__________________________________________________________________________________________________________________\n");
                printf("\t\t\t__________________________________________________________________________________________________________________\n");
                printf("\n\t\t\t\t\t\t\t\t\tCurrency List (%zu) Currency(s).\n", CurrenciesList.size());
                printf("\t\t\t__________________________________________________________________________________________________________________\n");
                printf("\n\n_________________________________________________________________________________________________________________________________________________________\n");
*/