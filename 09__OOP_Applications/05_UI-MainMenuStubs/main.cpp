
#include <iostream>
#include "Core/clsBankClient.hpp"
#include "Screens/Clients/clsMainScreen.hpp"
#include "Include/InputValidator.hpp"
#include "Include/CoreUtilities.hpp"

#include <fstream>

using namespace std;

//Static or not ? Not; you want to update exist Client!

void    printClientInfoCard(clsBankClient &Client)
{
    int cardWidth = 45;  // Width of the card block
    int totalWidth = 80; // Total terminal width
    int padding = (totalWidth - cardWidth) / 2;  // Padding for centering the card block

    std::cout << std::setw(padding) << std::right << "" << "Client Card:" << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "First Name   : " << Client.Firstname() << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "Last Name    : " << Client.Lastname() << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "Full Name    : " << Client.Fullname() << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "Email        : " << Client.Email() << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "Phone        : " << Client.PhoneNbr() << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "Acc. Number  : " << Client.AccountID() << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "Password     : " << Client.Password() << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "Balance      : " << std::fixed << std::setprecision(2) 
              << Client.balance() << std::endl;
    std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
    std::cout << std::endl;
}



void    ListOneBalanceRecordOfClient(clsBankClient &Client)
{
    printf("| %-25s | %-25s | %-25s | %-50s | %-40.5f \n", 
       Client.AccountID().c_str(),
        Client.Firstname().c_str(),
        Client.Lastname().c_str(),
        Client.Fullname().c_str(),
        Client.balance());
}



short   inputReadingClientInfo(clsBankClient &Client)
{
    char    proceed_fl = 'n';

    std::cout <<"\n\nPlease if you want to continue enter (y):  ";
    std::cin >> proceed_fl;
    if (tolower(proceed_fl) != 'y')
        return (1);                     //      Stop Input return

    // std::string SubHeader = "Client With ID Number:" + Client.AccountID();
    // clsMainScreen::drawScreensHeaders("Updating Client Information Screen", SubHeader);
    Client.setFirstname(InputValidator::readString("\n\nPlease enter First Name: "));
    Client.setLastname(InputValidator::readString("Please enter Last Name: "));
    Client.setEmail(InputValidator::readString("Please enter Email: "));
    Client.setPhoneNbr(InputValidator::readString("Please enter Phone Number: "));
    Client.setPassword(InputValidator::readString("Please enter Password: "));
    Client.setBalance(InputValidator::readRangedNumberDouble(0, std::numeric_limits<double>::max(), "Please enter the Balance: "));
    return (0);
}


short   UpdateClient()
{
    std::string  AccNbr;
    char    quit_fl = 't';

    AccNbr = InputValidator::readString("Please enter the Account Number:  ");
    while (!(clsBankClient::isClientExist(AccNbr)))
    {
        AccNbr = InputValidator::readString("Invalide Entered Number.\nPlease enter the Account Number Again or Press (q) to quit:  ");
        quit_fl = tolower(AccNbr[0]);
        if (quit_fl == 'q')
        {
            std::cout << "\nQuit Successfully.";
            return (2); // Indicating successful quit
        }
    }
    clsBankClient   Client = clsBankClient::Find(AccNbr);
    printClientInfoCard(Client);
    if (inputReadingClientInfo(Client) == 1)
        return (1);

    if (Client.Save() == clsBankClient::en_SaveResults::SV_SUCCEEDED)
    {
        std::cout <<  "\nAccount Updated Successfully :-)\n" << std::endl;
        printClientInfoCard(Client);
        return (0);
    }
    else if (Client.Save() != clsBankClient::en_SaveResults::SV_SUCCEEDED)
    {
        std::cout <<  "\nError account was not saved because it's Empty" << std::endl;
        return (-1);
    }

    return (0); //Indicating success in update
}


short   AddNewClient()
{
    std::string ID_Nbr;
    char    procceed_fl;

    procceed_fl = 'f';
    ID_Nbr = InputValidator::readString("Please enter the ID Number of the Client:  ");
    while (clsBankClient::isClientExist(ID_Nbr))
    {    
        ID_Nbr = InputValidator::readString("There is a Exist Client with thid ID Number.\nPlease enter new ID Number of the Client or press (q) to quit:  ");
        procceed_fl = ID_Nbr[0];
        if (tolower(procceed_fl) == 'q')
            return (1);                 //Quit using (q)
    }   
    clsBankClient Client = clsBankClient::AddNewClient(ID_Nbr);
    if(inputReadingClientInfo(Client))
        return (1);                     //Stop Input return 
    if (Client.Save() == clsBankClient::en_SaveResults::SV_SUCCEEDED)
    {
        std::cout <<  "\nAccount Added Successfully :-)\n" << std::endl;
        printClientInfoCard(Client);
        return (0);
    }
    else
    {
        std::cout <<  "\nError account was NOT saved!" << std::endl;
        return (-1);
    }
}


short   DeleteClient()
{

    std::string ID_Nbr;
    char    procceed_fl;

    procceed_fl = 'f';
    ID_Nbr = InputValidator::readString("Please enter the ID Number of the Client inorder to (Delete):  ");

    while (!(clsBankClient::isClientExist(ID_Nbr)))
    {    
        ID_Nbr = InputValidator::readString("There is (No) Exist Client with thid ID Number.\nPlease enter an (Exist ID Number) for a Client or press (q) to quit:  ");
        procceed_fl = ID_Nbr[0];
        if (tolower(procceed_fl) == 'q')
            return (1);                 //Quit using (q)
    }  
    clsBankClient Client = clsBankClient::Find(ID_Nbr);
    printClientInfoCard(Client);
    std::cout << "Are you sure that you want to proceed (deleting) of the client (Press (q) to (quit)!)?  ";
    std::cin >> procceed_fl;
    if (tolower(procceed_fl) == 'q')
        return (2);
    if (!(Client.DeleteClient()))
    {
        std::cout << "\n\nClient is deleted Successfully!\n\n";
        printClientInfoCard(Client);
        std::cout << "\n\nChecking if Client is exist in the Data File";
        if (!(clsBankClient::isClientExist(ID_Nbr)))
        {
            std::cout << "\n\n(Succeed)\nClient is not found in the Data files! :)";
            return (0);
        }
        else
        {
            std::cout << "\n\n\b(Unfortunately) Client is found in the Data files! :(";
            return (-1);        //	Client isn't Deleted
        }
    }
    return (3);
}




short   ShowTotalBalancesOfClients()
{
    std::vector <clsBankClient> ClientsList = clsBankClient::GetClientsListToVect();
    double  total_balances = clsBankClient::CalculateTotalBalancesOfClients();
    // std::vector <clsBankClient> ClientsList ;        //Test 0 Clients Display

	printf("\n\t\t\t__________________________________________________________________________________________________________________\n");
	printf("\t\t\t__________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t\t\t\tClient List (%zu) Client(s).\n", ClientsList.size());
	printf("\t\t\t__________________________________________________________________________________________________________________\n");
	printf("\n\n_________________________________________________________________________________________________________________________________________________________\n");



    printf("| %-25s | %-25s | %-25s | %-50s | %-40s", 
       "Account Number", "First Name", "Last Name", "Full Name", "Balance");
	printf("\n________________________________________________________________________________________________________________________________________________________\n");

	if (ClientsList.size() < 1)
    {
        std::cout << "\n\n\n\t\t\t\t\t\t\tThere is (No) Clients Avialable in the System :( :( : (\n\n\n";
        printf("________________________________________________________________________________________________________________________________________________________\n");
        printf("________________________________________________________________________________________________________________________________________________________\n\n\n");
        return (-1);            //      No Clients Avialable.
    }
    for (clsBankClient &Client: ClientsList)
		ListOneBalanceRecordOfClient(Client);


	printf("________________________________________________________________________________________________________________________________________________________\n");
	printf("________________________________________________________________________________________________________________________________________________________\n\n\n");

    printf("%75s (%f)\n", "Total Balances: ", total_balances);
    printf("%137s \n\n\n", CoreUtilities::NumberToText((long)total_balances).c_str());
    return (0);
}


int main()

{

    clsMainScreen::showMainMenu();

    return 0;
}