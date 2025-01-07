
#include <iostream>
#include "Core/clsBankClient.hpp"
#include "Include/InputValidator.hpp"
#include "Include/CoreUtilities.hpp"

#include <fstream>

#include "Screens/clsLoginScreen.hpp"

using namespace std;

int main()
{
    while (1)
    {
        clsLoginScreen::ShowLoginScreen();
    }

    return 0;
}