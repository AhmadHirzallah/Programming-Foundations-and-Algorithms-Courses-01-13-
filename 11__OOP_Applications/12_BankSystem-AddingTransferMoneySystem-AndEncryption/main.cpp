
#include <iostream>
#include "Core/clsBankClient.hpp"
#include "Core/clsBankUser.hpp"
#include "Include/InputValidator.hpp"
#include "Include/CoreUtilities.hpp"
#include "Include/DateUtils.hpp"

#include <fstream>

#include "Screens/clsLoginScreen.hpp"

using namespace std;

int main()
{
    //          To Decrypt Passwords from Users.txt File :)
    // std::cout << CoreUtilities::decryptText(";C::C;Jzk}}�y|n", 10) << std::endl;
    while (1)
    {
        clsLoginScreen::ShowLoginScreen();
    }

    // DateUtils::DateToString()
    // std::cout << "Date: " + DateUtils::DateToString(DateUtils::getSystemDate());

    // std::cout << "\n";
    return 0;
}