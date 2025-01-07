#pragma once

#ifndef	CLSCURRENCY
# define CLSCURRENCY 

# include <iostream>
# include "../Include/CoreUtilities.hpp"
# include "../Include/InputValidator.hpp"
# include "../Include/StringUtils.hpp"
# include "clsPerson.hpp"
# include <fstream>
# include <vector>
# include <string>
# include <pthread.h>
# include <string>

# include "../Include/Global.hpp"


class clsCurrency 
{

public:

        enum class  E_MODES
        {
            EMPTY,
            UPDATE_RATE
        };


        enum class  E_FIND
        {
            USE_COUNTRY,
            USE_CODE,
            COUNTRY_AND_CODE
        };
        

        clsCurrency(E_MODES MODE, std::string Name, std::string Country, std::string Code, double rate)
        {
            _Currency_Vars.MODE = MODE;
            _Currency_Vars.Name = Name;
            _Currency_Vars.Country = Country;
            _Currency_Vars.Code = Code;
            _Currency_Vars.rate = rate;
        };


        bool    isExist()
        {
            return (!(_isEmpty()));
        }
        

        static bool    isExist(std::string SearchFor)
        {
            clsCurrency Currency = Find(SearchFor, E_FIND::COUNTRY_AND_CODE);

            return (!(Currency._isEmpty()));
        }


        std::string Name()
        {
            return (_Currency_Vars.Name);
        }

        std::string Country()
        {
            return (_Currency_Vars.Country);
        }

        std::string Code()
        {
            return (_Currency_Vars.Code);
        }

        double  Rate()
        {
            return (_Currency_Vars.rate);
        }

        void    setRate(double newRate)
        {
            _Currency_Vars.rate = newRate;
        }

        short   updateRate(double newRate)
        {
            if (newRate < 0)
                return 1;
            setRate(newRate);
            _SaveUpdate();
            return 0;           // Succeed
        }


        static std::vector <clsCurrency>    getCurrenciesListVec()
        {
            return (_LoadCurrencysObjsFromFile());
        }


        static clsCurrency Find(std::string Search, E_FIND Type = E_FIND::COUNTRY_AND_CODE)
        {
            if (Type == E_FIND::USE_CODE)
                return (_FindByCode(Search));
            else if (Type == E_FIND::USE_COUNTRY)
                return (_FindByCountry(Search));
            else if (Type == E_FIND::COUNTRY_AND_CODE)
            {
                clsCurrency Currency = _FindByCode(Search);
                if (Currency.isExist())
                    return Currency;
                else
                    return (_FindByCountry(Search));
            }
            else
                return (_rtrnEmptyObj());
        }


/*

        Random Currency     ----->      USD

        1 dolar           ->  0.7 dinar
       (to usd) x dolar   ->  50 dinar

       x = (50 * 1 / 0.7) = (50 / 0.7)

*/


        double   rateToUSD(double amount)
        {
            double rateInUSD = 0;

            rateInUSD = (amount / (this->_Currency_Vars.rate));

            return rateInUSD;
        }


/*
        1 dolar           ->  0.7 dinar
       (to usd) x dolar   ->  50 dinar
       x = (50 * 1 / 0.7) = (50 / 0.7)

       1 dolar           ->  0.7 dinar
       (to usd) x dolar   ->  1 dinar
       x = (50 * 1 / 0.7) = (1 / 0.7)
    
       Dinar To Euro

       X Dinar      ->      Y Dolar -----> DinarsNbr / (rate:(0.7)) = Y Dolar

       Y Dolar      ->      Z Euro
       1 Dolar      ->      0.93 EURO
       
       (Y Dolar (Know))  * 0.93 = ((Y * 0.93) = Z Euro)
*/


        double  currencyConverter(double amount, std::string Search = "USD")
        {
            clsCurrency Currency = Find(Search);

            double amountInUSD = rateToUSD(amount);
            if (StringUtils::toLowerAllString(Currency.Code()) == StringUtils::toLowerAllString("usd")) 
                return (amountInUSD);

            return (amountInUSD * Currency.Rate());

        }

private:


        struct  Currency_Vars
        {
            E_MODES MODE;
            std::string Name;
            std::string Country;
            std::string Code;
            double  rate;
        };
        
        Currency_Vars _Currency_Vars ;

        
        bool    _isEmpty()
        {
            return (this->_Currency_Vars.MODE == E_MODES::EMPTY);
        }



        static clsCurrency  _ConvertLineIntoCurrencyObj(std::string FileRecodLine)
        {
            std::vector <std::string>	CurrencyDataSections;

            CurrencyDataSections = StringUtils::splitByDelim(FileRecodLine, "#//#", StringUtils::e_split_type::MULTI);

            return (clsCurrency(E_MODES::UPDATE_RATE, CurrencyDataSections[2], CurrencyDataSections[0],
                                 CurrencyDataSections[1],   std::stod(CurrencyDataSections[3])));
                       
        }

        static std::vector <clsCurrency>	_LoadCurrencysObjsFromFile(std::string FileName = "data/Currencies.txt")
        {
            std::vector <clsCurrency> CurrenciesVec;
            std::fstream							FileCtrl;
            std::string								CurrencyDataLine;

            FileCtrl.open(FileName,	std::ios::in);
            if (FileCtrl.is_open())
            {
                while (getline(FileCtrl, CurrencyDataLine))
                {
                    clsCurrency	CurrencyObj =   _ConvertLineIntoCurrencyObj(CurrencyDataLine);
                    CurrenciesVec.push_back(CurrencyObj);
                }
                FileCtrl.close();
            }
            return (CurrenciesVec);
        }


        std::string _ConvertCurrencyToDataLine(clsCurrency Currency , std::string separator = "#//#")
        {
            return (
                        (Currency._Currency_Vars.Country + separator)     + (Currency._Currency_Vars.Code + separator) +\
                        (Currency._Currency_Vars.Name + separator)      + std::to_string(Currency._Currency_Vars.rate)
                    );
        }



        short	_SaveCurrenciesObjsToFile(std::vector <clsCurrency>	&CurrenciesVec, std::string FileName = "data/Currencies.txt")
        {
            std::fstream	FileCtrl;
            std::string		FileDataLine;

            FileCtrl.open(FileName ,	std::ios::out);
            if (FileCtrl.is_open())
            {
                for (clsCurrency &Currency : CurrenciesVec)
                {
                    FileDataLine = _ConvertCurrencyToDataLine(Currency);
                    FileCtrl << FileDataLine << std::endl; 
                }
                FileCtrl.close();
                return (0);				//Succeed in Saving.	 :)
            }
            return (-1);					//Case of Error ::: Saving Failed. 		 :(
        }

        short   _SaveUpdate()
        {
            std::vector <clsCurrency> CurrenciesVec =  _LoadCurrencysObjsFromFile();
            
            for (clsCurrency &Currency : CurrenciesVec)
            {
                if (Currency._Currency_Vars.Name == this->Name())
                    Currency = *this;
            }

            if (!(_SaveCurrenciesObjsToFile(CurrenciesVec)))
                return 0;       //  Succeed
            else
                return 1;
        }


        static clsCurrency _rtrnEmptyObj()
        {
            return (clsCurrency(E_MODES::EMPTY, "", "", "" , 0.0));
        }

        static clsCurrency _FindByCountry(std::string   Country, std::string FileName = "data/Currencies.txt")
        {
            std::fstream							FileCtrl;
            std::string								CurrencyDataLine;

            FileCtrl.open(FileName ,	std::ios::in);
            if (FileCtrl.is_open())
            {
                while (getline(FileCtrl, CurrencyDataLine))
                {
                    clsCurrency	Currency =   _ConvertLineIntoCurrencyObj(CurrencyDataLine);
                    if (StringUtils::toLowerAllString(Currency._Currency_Vars.Country) == StringUtils::toLowerAllString(Country))
                        return (Currency);

                }
                FileCtrl.close();
            }

            return _rtrnEmptyObj();
        }

        static clsCurrency _FindByCode(std::string   Code, std::string FileName = "data/Currencies.txt")
        {
            std::vector <clsCurrency> CurrenciesVec;
            std::fstream							FileCtrl;
            std::string								CurrencyDataLine;

            FileCtrl.open(FileName,	std::ios::in);
            if (FileCtrl.is_open())
            {
                while (getline(FileCtrl, CurrencyDataLine))
                {
                    clsCurrency	Currency =   _ConvertLineIntoCurrencyObj(CurrencyDataLine);
                    if ((StringUtils::toLowerAllString(Currency._Currency_Vars.Code) == StringUtils::toLowerAllString(Code)))
                        return (Currency);

                }
                FileCtrl.close();
            }

            return _rtrnEmptyObj();
        }



};




#endif