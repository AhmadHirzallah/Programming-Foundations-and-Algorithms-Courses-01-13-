#pragma once

#ifndef CLSTRANSFERHISTORYREGISTERSCREEN_HPP
# define CLSTRANSFERHISTORYREGISTERSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"
# include "clsClientsSuperScreen.hpp"


class clsTransferHistoryRegisterScreen : protected clsScreen
{
private:



    static void _DisplayTitles()
    {
                printf("| %-25s | %-12s | %-12s | %-22s | %-22s | %-22s | %-17s |\n", 
                        "Date/Time", "SRC ID", "DST ID", "Amount", "SRC Balance", "DST Balance", "User");

    }


    static void    _ListOneTransferRecord(clsBankClient::s_TransferRecord &TransferRecord)
    {
        printf("\n| %-25s | %-12s | %-12s | %-22.2f | %-22.2f | %-22.2f | %-17s |\n", 
            TransferRecord.DateAndTime.c_str(),
            TransferRecord.SenderID.c_str(), 
            TransferRecord.ReceiverID.c_str(), 
            TransferRecord.transfer_amount,         //Double
            TransferRecord.sender_balance_after,    //Double
            TransferRecord.receiver_balance_after,  //Double
            TransferRecord.SenderUsername.c_str());
    }


    static  void    _DisplayRecords(std::vector <clsBankClient::s_TransferRecord> vListOfTransferLogs)
    {
        if (vListOfTransferLogs.size() < 1)
        {
            std::cout << "\n\n\n\t\t\t\t\t\t\tThere is (No) Transfer Records Are Registered in the System :( :( : (\n\n\n";
            printf("________________________________________________________________________________________________________________________________________________________\n");
            printf("________________________________________________________________________________________________________________________________________________________\n\n\n");
            return ;
        }

        
        for (clsBankClient::s_TransferRecord &TransferRecord : vListOfTransferLogs)
            _ListOneTransferRecord(TransferRecord);

        printf("\n________________________________________________________________________________________________________________________________________________________\n\n\n");

}


public:


    static void ShowTransferHistoryRegisterScreen()
    {
        std::vector <clsBankClient::s_TransferRecord> vListOfTransferLogs;
        
        vListOfTransferLogs = clsBankClient::GetTransferRegListVector();

        std::string Subtitle = "("+ std::to_string(vListOfTransferLogs.size()) +  ")  Record(s)";

        drawScreensHeaders("Login Registers List Screen", Subtitle);

        _DisplayTitles();

        _DisplayRecords(vListOfTransferLogs);

    }

};



#endif