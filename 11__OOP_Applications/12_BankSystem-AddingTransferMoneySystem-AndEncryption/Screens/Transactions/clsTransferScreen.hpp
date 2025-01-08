
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

        struct s_TransferScreenVars
        {
            std::string SenderID_Nbr;
            std::string ReceiverID_Nbr;
            char    procceed_fl;
            double  transfer_val;
            clsBankClient SenderClient = clsBankClient::Find("", "");
        };
        

        static  short _ReadReceiver(s_TransferScreenVars &Vars)
        {
                //      Receiver Info
                Vars.ReceiverID_Nbr = InputValidator::readString("\n\nPlease enter the ID Number of the Client To Transfer (TO --  Receiver):  ");

                while (!(clsBankClient::isClientExist(Vars.ReceiverID_Nbr)))
                {    
                    Vars.ReceiverID_Nbr = InputValidator::readString(
                 "There is (No) Exist Client with thid ID Number.\nPlease enter an (Exist ID Number) for a Client or press (q) to quit:  "
                                                        );
                    Vars.procceed_fl = Vars.ReceiverID_Nbr[0];
                    if (tolower(Vars.procceed_fl) == 'q')
                        return 2;                 //Quit using (q)
                }

            return 0;
        }
        

        static  short _ReadSender(s_TransferScreenVars &Vars)
        {

            //      Sender Info
            Vars.SenderID_Nbr = InputValidator::readString("\n\nPlease enter the ID Number of the Client To Transfer (FROM --  Sender):  ");

            while (!(clsBankClient::isClientExist(Vars.SenderID_Nbr)))
            {    
                Vars.SenderID_Nbr = InputValidator::readString(
                "There is (No) Exist Client with thid ID Number.\nPlease enter an (Exist ID Number) for a Client or press (q) to quit:  "
                                                    );
                Vars.procceed_fl = Vars.SenderID_Nbr[0];
                if (tolower(Vars.procceed_fl) == 'q')
                    return 1;                 //Quit using (q)
            }

            return 0;
        }


    public:

            static short    showTransferScreen()
            {
                
                s_TransferScreenVars Vars;

                drawScreensHeaders("Money Transfer");



                if (_ReadSender(Vars))
                    return 1;                 //Quit using (q)

                Vars.SenderClient = clsBankClient::Find(Vars.SenderID_Nbr);
                printClientCard_EssintialInfo(Vars.SenderID_Nbr);


                if (_ReadReceiver(Vars))
                    return 2;

                printClientCard_EssintialInfo(Vars.ReceiverID_Nbr);

                
                while (1)
                {
                    Vars.transfer_val = InputValidator::readRangedNumberDouble(0, std::numeric_limits<double>::max(),
                                                                        "\nPlease enter the Amount inorder to Perform Transfer ($):  "
                                                                         );

                    if (Vars.SenderClient.balance() < Vars.transfer_val)
                    {
                        std::cout << "\n\nUnfortunately, Failed to Transfer the Money." << std::endl;
                        std::cout << "\n\nNo Sufficient Balance!!!\n" << std::endl;
                        continue;
                    }
                    else 
                    {
                        Vars.procceed_fl = InputValidator::readChr("\n\nAre you sure that you want to proceed and Perform this Transfer (y to continue)?  ");
                       
                        if (tolower(Vars.procceed_fl) != 'y')
                            return 3;

                        if (!(Vars.SenderClient.Transfer(Vars.transfer_val, Vars.ReceiverID_Nbr)))
                        {
                            std::cout << "\n\n\nMoney Transfered Successfully.\n\nBalances after are:" << std::endl;

                            printClientCard_EssintialInfo(Vars.SenderID_Nbr);
                            std::cout << "\n\n" << std::endl;
                            printClientCard_EssintialInfo(Vars.ReceiverID_Nbr);
                            std::cout << "\n\n" << std::endl;
                            return 0;
                        }
                        else if (Vars.SenderClient.Transfer(Vars.transfer_val, Vars.ReceiverID_Nbr) == 2)
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