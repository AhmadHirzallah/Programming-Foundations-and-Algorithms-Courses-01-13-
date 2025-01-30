
#pragma once

#ifndef CLStransferSCREEN_HPP
# define  CLStransferSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankClient.hpp"

# include "../Clients/clsClientsSuperScreen.hpp"

// # include "../../Include/Global.hpp"         /// / We Deal With Clients; Not user :(


class clsTransferScreen : protected clsClientsSuperScreen
{

    private:

        struct s_TransferScreen_struct
        {
            std::string SenderID_Nbr;
            std::string ReceiverID_Nbr;
            char    procceed_fl;
            double  transfer_val;
            clsBankClient SenderClient = clsBankClient::Find("", "");
        };
        

        static  short _ReadReceiver(s_TransferScreen_struct &_struct)
        {
                //      Receiver Info
                _struct.ReceiverID_Nbr = InputValidator::readString("\n\nPlease enter the ID Number of the Client To Transfer (TO --  Receiver):  ");

                while (!(clsBankClient::isClientExist(_struct.ReceiverID_Nbr)))
                {    
                    _struct.ReceiverID_Nbr = InputValidator::readString(
                 "There is (No) Exist Client with thid ID Number.\nPlease enter an (Exist ID Number) for a Client or press (q) to quit:  "
                                                        );
                    _struct.procceed_fl = _struct.ReceiverID_Nbr[0];
                    if (tolower(_struct.procceed_fl) == 'q')
                        return 2;                 //Quit using (q)
                }

            return 0;
        }
        

        static  short _ReadSender(s_TransferScreen_struct &_struct)
        {

            //      Sender Info
            _struct.SenderID_Nbr = InputValidator::readString("\n\nPlease enter the ID Number of the Client To Transfer (FROM --  Sender):  ");

            while (!(clsBankClient::isClientExist(_struct.SenderID_Nbr)))
            {    
                _struct.SenderID_Nbr = InputValidator::readString(
                "There is (No) Exist Client with thid ID Number.\nPlease enter an (Exist ID Number) for a Client or press (q) to quit:  "
                                                    );
                _struct.procceed_fl = _struct.SenderID_Nbr[0];
                if (tolower(_struct.procceed_fl) == 'q')
                    return 1;                 //Quit using (q)
            }

            return 0;
        }


    public:

            static short    showTransferScreen()
            {
                
                s_TransferScreen_struct _struct;

                drawScreensHeaders("Money Transfer");



                if (_ReadSender(_struct))
                    return 1;                 //Quit using (q)

                _struct.SenderClient = clsBankClient::Find(_struct.SenderID_Nbr);
                printClientCard_EssintialInfo(_struct.SenderID_Nbr);


                if (_ReadReceiver(_struct))
                    return 2;

                printClientCard_EssintialInfo(_struct.ReceiverID_Nbr);

                
                while (1)
                {
                    _struct.transfer_val = InputValidator::readRangedNumberDouble(0, std::numeric_limits<double>::max(),
                                                                        "\nPlease enter the Amount inorder to Perform Transfer ($):  "
                                                                         );

                    if (_struct.SenderClient.balance() < _struct.transfer_val)
                    {
                        std::cout << "\n\nUnfortunately, Failed to Transfer the Money." << std::endl;
                        std::cout << "\n\nNo Sufficient Balance available !!!\n" << std::endl;
                        continue;
                    }
                    else 
                    {
                        _struct.procceed_fl = InputValidator::readChr("\n\nAre you sure that you want to proceed and Perform this Transfer (y to continue)?  ");
                       
                        if (tolower(_struct.procceed_fl) != 'y')
                            return 3;

                        if (!(_struct.SenderClient.Transfer(_struct.transfer_val, _struct.ReceiverID_Nbr)))
                        {
                            std::cout << "\n\n\nMoney Transfered Successfully.\n\nBalances after are:" << std::endl;

                            printClientCard_EssintialInfo(_struct.SenderID_Nbr);
                            std::cout << "\n\n" << std::endl;
                            printClientCard_EssintialInfo(_struct.ReceiverID_Nbr);
                            std::cout << "\n\n" << std::endl;
                            return 0;
                        }
                        else if (_struct.SenderClient.Transfer(_struct.transfer_val, _struct.ReceiverID_Nbr) == 2)
                        {
                            std::cout << "\n\nUnfortunately, Failed to Transfer the Money." << std::endl;
                            std::cout << "\n\nNo Sufficient Balance!!!" << std::endl;
                            continue;
                        }

                    }
                }
                return 0;
            }    

};


# endif