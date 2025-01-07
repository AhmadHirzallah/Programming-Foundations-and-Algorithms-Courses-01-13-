#pragma once

#ifndef CLSSHOWALLUSERSSCREEN_HPP
# define CLSSHOWALLUSERSSCREEN_HPP


# include <cstdio>
# include <vector>
# include "../clsScreen.hpp"
# include "clsUsersSuperScreen.hpp"
# include "../../Core/clsBankUser.hpp"


class clsShowAllUsersScreen : protected clsUsersSuperScreen
{



private:


        static void    ListOneUser(clsBankUser &User)
        {
            printf("\t| %-15s | %-25s | %-30s | %-25s | %-25s |   %-4i\n", 
                User.Username().c_str(), 
                User.Password().c_str(), 
                User.Fullname().c_str(),
                User.PhoneNbr().c_str(), 
                User.Email().c_str(), 
                User.Permissions());
        }


public:


        static short    ShowUsersListScreen()
        {
            std::vector UsersList = clsBankUser::GetBankUsersListToVect();
            // std::vector <clsBankUser> UsersList ;        //Test 0 Users Display

            std::string subtitle = "(" + std::to_string(UsersList.size()) + ") User(s)" ;
            drawScreensHeaders("List Users Screen", subtitle);
           
            printf("\t| %-15s | %-25s | %-30s | %-25s | %-25s | %-4s\n", 
            "Username", "Password", "Fullname", "Phone Number", "Email", "Permissions");
           
            printf("\t____________________________________________________________________________________________________________________________________________________\n");

            if (UsersList.size() < 1)
            {
                std::cout << "\n\n\n\t\t\t\t\t\t\tThere is (No) Users Avialable in the System :( :( : (\n\n\n";
                printf("\t____________________________________________________________________________________________________________________________________________________\n");
                printf("\t____________________________________________________________________________________________________________________________________________________\n");

                return (-1);            //      No Users Avialable.
            }
            for (clsBankUser &User: UsersList)
                ListOneUser(User);

                printf("\t____________________________________________________________________________________________________________________________________________________\n");
                printf("\t____________________________________________________________________________________________________________________________________________________\n");

            return (0);                 //      Everything Worked Correctly.
        }

};

#endif


