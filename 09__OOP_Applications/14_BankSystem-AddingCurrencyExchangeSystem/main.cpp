
#include <iostream>
#include "Core/clsBankClient.hpp"
#include "Core/clsBankUser.hpp"
#include "Core/clsCurrency.hpp"
#include "Include/InputValidator.hpp"
#include "Include/CoreUtilities.hpp"
#include "Include/DateUtils.hpp"

#include <fstream>

#include "Screens/clsLoginScreen.hpp"
#include "Screens/Currency/clsFindCurrencyScreen.hpp"

using namespace std;


int main()
{
    while (1)
    {
        clsLoginScreen::ShowLoginScreen();
    }


    return 0;
}