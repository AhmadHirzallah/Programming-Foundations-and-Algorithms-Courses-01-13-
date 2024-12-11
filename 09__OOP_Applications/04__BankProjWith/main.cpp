
#include <iostream>
#include "Core/clsBankClient.hpp"
#include "Screens/Clients/clsMainScreen.hpp"
#include "Screens/Clients/clsAddNewClientScreen.hpp"

using namespace std;

int main()

{
    CoreUtilities::sRand();
    // clsMainScreen::showMainMenu();
    DateUtils::printYearCalendar(2024);









    // cout << CoreUtilities::generateRandomChr(CoreUtilities::e_char_type::CAPITAL) << endl;
    // cout << CoreUtilities::generateRandomChr(CoreUtilities::e_char_type::DIGIT) << endl;
    // cout << CoreUtilities::generateRandomChr(CoreUtilities::e_char_type::MIX) << endl;
    // cout << CoreUtilities::generateRandomChr(CoreUtilities::e_char_type::SMALL) << endl;
    // cout << CoreUtilities::generateRandomChr(CoreUtilities::e_char_type::SPECIAL_CHRS) << endl;

    
    return 0;
}
/*
    // clsBankClient Client1 = clsBankClient::Find("A109");
    // if (!Client1.isEmpty())
    // {
    //     cout << "\nClient Found :-)\n";
    // } 
    // else
    // {
    //     cout << "\nClient Was not Found :-(\n";
    // }
    
    // Client1.Print();

    // clsBankClient Client2 = clsBankClient::Find("A101", "12345");
    // if (!Client2.isEmpty())
    // {
    //     cout << "\nClient Found :-)\n";
    // }
    // else
    // {
    //     cout << "\nClient Was not Found :-(\n";
    // }
    // Client2.Print();

    
    // cout << "\nIs Client Exist? "<< clsBankClient::isClientExist("A109");

*/