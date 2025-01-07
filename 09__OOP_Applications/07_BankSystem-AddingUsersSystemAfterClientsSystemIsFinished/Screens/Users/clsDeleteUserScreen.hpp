#ifndef CLSDELETEUSERSCREEN_HPP
# define CLSDELETEUSERSCREEN_HPP

# include <cstdio>
# include "../clsScreen.hpp"
# include "../../Core/clsBankUser.hpp"
# include "clsUsersSuperScreen.hpp"



class clsDeleteUserScreen : protected clsUsersSuperScreen
{
private:

//

public:

    static short   ShowDeleteUserScreen()
    {
        std::string Username;
        char    procceed_fl;

        drawScreensHeaders("Delete User Screen");

        procceed_fl = 'f';
        Username = InputValidator::readString("\n\nPlease enter the Username inorder to (Delete):  ");

        while (!(clsBankUser::isUserExist(Username)))
        {    
            Username = InputValidator::readString\
                ("There is (No) Exist User with thid Username.\nPlease enter an (Valid Username) for a User or press (q) to quit:  ");
           
            procceed_fl = Username[0];
            if (tolower(procceed_fl) == 'q')
                return (1);                 //Quit using (q)
        }  

        clsBankUser User = clsBankUser::Find(Username);

        printUserInfoCard(User);

        std::cout << "Are you sure that you want to proceed (Deleting) of the User? (Press (q) to (Quit)!):  ";
        std::cin >> procceed_fl;
        if (tolower(procceed_fl) == 'q')
            return (2);
        if (!(User.DeleteBankUserThenSave()))
        {
            std::cout << "\n\nUser is deleted Successfully!\n\n";
            printUserInfoCard(User);



            std::cout << "\n\nChecking if User is exist in the Data File:";
//        Or We can Use this:
//          if (!(clsBankUser::isUserExist(Username)))
            if (!(User.isUserExist()))
            {
                std::cout << "\n\n(Succeed)! :)\nUser is not found in the Data files!\n\n";
                return (0);
            }
            else
            {
                std::cout << "\n\n\b(Unfortunately) User is found in the Data files! :(";
                return (-1);        //	User isn't Deleted
            }
        }
        return (3);
    }

};




# endif