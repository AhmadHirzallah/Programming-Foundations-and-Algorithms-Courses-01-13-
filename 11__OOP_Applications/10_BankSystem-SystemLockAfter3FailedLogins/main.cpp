
#include <iostream>
#include "Core/clsBankClient.hpp"
#include "Include/InputValidator.hpp"
#include "Include/CoreUtilities.hpp"
#include "Include/DateUtils.hpp"

#include <fstream>

#include "Screens/clsLoginScreen.hpp"

using namespace std;

int main()
{
    while (1)
    {
        clsLoginScreen::ShowLoginScreen();
    }

    // DateUtils::DateToString()
    // std::cout << "Date: " + DateUtils::DateToString(DateUtils::getSystemDate());

    // std::cout << "\n";
    return 0;
}