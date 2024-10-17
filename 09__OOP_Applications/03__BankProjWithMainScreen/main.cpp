
#include <iostream>
#include "Core/clsBankClient.hpp"
#include "Screens/Clients/clsMainScreen.hpp"

using namespace std;

int main()

{

    clsMainScreen::showMainMenu();
    
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