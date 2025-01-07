#pragma once

#ifndef CLSLOGINHISTORYREGSCREEN	
# define	CLSLOGINHISTORYREGSCREEN	

# include "../Include/CoreUtilities.hpp"
# include "../Include/DateUtils.hpp"
# include "../Include/InputValidator.hpp"
# include "../Include/StringUtils.hpp"
# include "clsScreen.hpp"

# include "../Include/Global.hpp"
# include "clsMainScreen.hpp"


class clsLoginHistoryRegScreen : protected clsScreen
{

private:
        


static void _DisplayTitles()
{
    printf("\n\n| %-50s | %-37s | %-37s | %-40s", 
    "Date/Time", "Username", "Password", "Permissions");
    printf("\n________________________________________________________________________________________________________________________________________________________\n");

}


static void    _ListOneLoginRegisterRecord(clsBankUser::s_LoginRegister &LoginRecord)
{
    printf("\n| %-50s | %-37s | %-37s | %-40i", 
    LoginRecord.DateAndTime.c_str(),
        LoginRecord.Username.c_str(),
        LoginRecord.Password.c_str(),
        LoginRecord.Permission);
}


static  void    _DisplayRecords(std::vector <clsBankUser::s_LoginRegister> vListOfLoginRegs)
{
    if (vListOfLoginRegs.size() < 1)
    {
        std::cout << "\n\n\n\t\t\t\t\t\t\tThere is (No) Records Are Registered in the System :( :( : (\n\n\n";
        printf("________________________________________________________________________________________________________________________________________________________\n");
        printf("________________________________________________________________________________________________________________________________________________________\n\n\n");
        return ;
    }

    
    for (clsBankUser::s_LoginRegister &LoginRecord : vListOfLoginRegs)
        _ListOneLoginRegisterRecord(LoginRecord);

    printf("\n________________________________________________________________________________________________________________________________________________________\n\n\n");

}





public:


static void ShowLoginHistoryRegisterScreen()
{
    std::vector <clsBankUser::s_LoginRegister> vListOfLoginRegs;
    
    vListOfLoginRegs = clsBankUser::GetLoginRegRecordsList();

    std::string Subtitle = "("+ std::to_string(vListOfLoginRegs.size()) +  ")  Record(s)";

    drawScreensHeaders("Login Registers List Screen", Subtitle);

    _DisplayTitles();

    _DisplayRecords(vListOfLoginRegs);

}



};




#endif