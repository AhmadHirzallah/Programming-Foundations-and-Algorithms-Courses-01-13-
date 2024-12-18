
#include <iostream>
#include "Core/clsBankClient.hpp"
#include "Screens/Clients/clsMainScreen.hpp"
#include <fstream>

using namespace std;

int main()

{

    // clsMainScreen::showMainMenu();
    
    std::cout << clsBankClient::Find("A101", "1234").balance();
    return 0;
}




       /*
                std::fstream FileSystem;
                    FileSystem.open("./Data/Clients.txt", std::ios::in);

                if (!FileSystem)
                {
                    std::cerr << "Error: Could not open the file at './Data/Clients.txt'\n";
                    return 1; // Exit with error
                }

                std::cout << "File opened successfully!\n";
                std::string line;

                // Read the file contents
                while (std::getline(FileSystem, line))
                {
                    std::cout << line << std::endl;
                }
    */









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