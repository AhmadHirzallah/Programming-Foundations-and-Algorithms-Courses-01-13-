#pragma once

#ifndef CLSBANKUSER_HPP
# define CLSBANKUSER_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <string>
# include <pthread.h>


# include "clsPerson.hpp"
# include "../Include/CoreUtilities.hpp"
# include "../Include/InputValidator.hpp"
# include "../Include/StringUtils.hpp"



class clsBankUser : public clsPerson
{

public:


    struct s_LoginRegister
    {
        std::string Username;
        std::string Password;
        std::string DateAndTime;
        int Permission;
    };



private:

    enum class E_MODE
    {
        EMPTY_MODE,
        UPDATE_MODE,
        ADD_MODE
    };




    std::string _Username;
    std::string _Password;
    int                     _permissions;
    E_MODE              _MODE;


    static clsBankUser _ConvertLineIntoUser(std::string FileRecodLine)
    {
        std::vector <std::string>	clsBankUserDataSections;

        clsBankUserDataSections = StringUtils::splitByDelim(FileRecodLine, "#//#", StringUtils::e_split_type::MULTI);

        return (clsBankUser(E_MODE::UPDATE_MODE, clsBankUserDataSections[0], clsBankUserDataSections[1], clsBankUserDataSections[2],
                    clsBankUserDataSections[3], clsBankUserDataSections[4], clsBankUserDataSections[5], (std::stoi(clsBankUserDataSections[6]))));
    }

    static clsBankUser	_rtrnEmptyUserObject()
    {
        return (clsBankUser(E_MODE::EMPTY_MODE, "", "", "", "", "", "", 0));
    }

    bool    _isEmpty()
    {
        return (_MODE == E_MODE::EMPTY_MODE);
    }

    static std::string  _ConvertUserObjToLine(clsBankUser User, std::string Seperator = "#//#")
    {
        std::string ObjLine = "";

        ObjLine += (User.Firstname() + Seperator) + (User.Lastname() + Seperator) + (User.Email() + Seperator)\
                    + (User.PhoneNbr() + Seperator) + (User.Username() + Seperator)\
                    + (User.Password() + Seperator) + (std::to_string(User.Permissions()));

        return (ObjLine);
    }


    static std::vector <clsBankUser>	_LoadUsersFromFile(std::string Filename = "Data/Users.txt")
    {
        std::vector <clsBankUser> clsBankUsersVec;
        std::fstream							FileCtrl;
        std::string								FileDataLine;

        FileCtrl.open(Filename,	std::ios::in);
        if (FileCtrl.is_open())
        {
            while (getline(FileCtrl, FileDataLine))
            {
                clsBankUser	UserObj = _ConvertLineIntoUser(FileDataLine);
                clsBankUsersVec.push_back(UserObj);
            }
            FileCtrl.close();
        }
        return (clsBankUsersVec);
    }


    short	_SaveUsersObjsToFile(std::vector <clsBankUser>	&UsersVec, std::string Filename = "Data/Users.txt")
    {
        std::fstream	FileCtrl;
        std::string		FileDataLine;

        FileCtrl.open(Filename,	std::ios::out);
        if (FileCtrl.is_open())
        {
            for (clsBankUser &User : UsersVec)
            {
                FileDataLine = _ConvertUserObjToLine(User);
                FileCtrl << FileDataLine << std::endl; 
            }
            FileCtrl.close();
            return (0);				//Succeed in Saving.	 :)
        }
        return (-1);					//Case of Error ::: Saving Failed. 		 :(
    }

    short	_Update()
    {
        std::vector <clsBankUser>	clsBankUsersVec = _LoadUsersFromFile();

        if (clsBankUsersVec.size() > 0)
            for (clsBankUser &clsBankUser : clsBankUsersVec)
            {
                if (clsBankUser.Username() == this->Username())
                {
                    clsBankUser = *this;
                    if (!(_SaveUsersObjsToFile(clsBankUsersVec)))
                        return (0);             //Succeed in Saving.	 :)
                    else
                        break;
                }
            }
            
        return (-1);	// Case of Error ::: Updating Failed
    }



    short _AppendAddedUserDataLineToFile(std::string DataLine, std::string Filename = "Data/Users.txt")
    {
        std::fstream	FileSystem;

        FileSystem.open(Filename, std::ios::app | std::ios::out);
        if (FileSystem.is_open())
        {
            FileSystem << DataLine << std::endl;
            FileSystem.close();
            return (0);			//	Added Successfully
        }
        return (-1);		//Failed to add
    }


    short	_AddNewUser()
    {
        std::string DataLine;
        
        DataLine = _ConvertUserObjToLine(*this);
        if (!(_AppendAddedUserDataLineToFile(DataLine)))
            return (0);			//	Added Successfully

        return (-1); 								// Failed To ADD !!
    }

    s_LoginRegister   _PrepareLoginRegisterRecordInfo()
    {
        s_LoginRegister LoginInfo;

        LoginInfo.DateAndTime = DateUtils::getSystemDateAndTimeStr();
        LoginInfo.Username = this->Username();
        LoginInfo.Password = this->Password();
        LoginInfo.Permission = this->Permissions();

        return (LoginInfo);
    }


    std::string _ConvertLoginRecToRegisterLine(std::string Separator = "#//#")
    {
        s_LoginRegister LoginRegisterInfo = _PrepareLoginRegisterRecordInfo();

        return (LoginRegisterInfo.DateAndTime + Separator + LoginRegisterInfo.Username + Separator +\
                LoginRegisterInfo.Password + Separator + std::to_string(LoginRegisterInfo.Permission));
    } 


    static short    _AppendLoginRecordIntoRegisterFile(std::string DataLine, std::string Filename = "Data/LoginRegisters.txt")
    {
        std::fstream	FileSystem;

        FileSystem.open(Filename, std::ios::app | std::ios::out);
        if (FileSystem.is_open())
        {
            FileSystem << DataLine << std::endl;
            FileSystem.close();
            return (0);			//	Added Successfully
        }
        return (-1);		//Failed to add   
    }






    static s_LoginRegister    _ConvertLoginRegLineToLoginRegS(std::string FileRecodLine)
    {
        s_LoginRegister LoginRecord;
        std::vector <std::string>	LoginRecordDataSections;

        LoginRecordDataSections = StringUtils::splitByDelim(FileRecodLine, "#//#", StringUtils::e_split_type::MULTI);

        LoginRecord.DateAndTime = LoginRecordDataSections[0];
        LoginRecord.Username = LoginRecordDataSections[1];
        LoginRecord.Password = LoginRecordDataSections[2];
        LoginRecord.Permission = stoi(LoginRecordDataSections[3]);

        return (LoginRecord);
    }



    static std::vector <s_LoginRegister>	_LoadLoginRegRecordsFromFile(std::string Filename = "Data/LoginRegisters.txt")
    {
        std::vector <s_LoginRegister> s_LoginRegistersVec;
        s_LoginRegister         LoginRegisterRecord;	
        std::fstream							FileCtrl;
        std::string								FileDataLine;

        FileCtrl.open(Filename,	std::ios::in);
        if (FileCtrl.is_open())
        {
            while (getline(FileCtrl, FileDataLine))
            {
                LoginRegisterRecord = _ConvertLoginRegLineToLoginRegS(FileDataLine);
                s_LoginRegistersVec.push_back(LoginRegisterRecord);
            }
            FileCtrl.close();
        }
        return (s_LoginRegistersVec);
    }







public:




    clsBankUser(E_MODE MODE, std::string Firstname, std::string Lastname , std::string Email, std::string PhoneNbr
                , std::string Username, std::string Password, int permissions
                )   : clsPerson(Firstname, Lastname, Email, PhoneNbr)
    {

            _MODE = MODE;
            _Username = Username;
            _Password = Password;
            _permissions = permissions;
    }



    clsBankUser(E_MODE MODE, std::string Fullname, std::string Email, std::string PhoneNbr
                , std::string Username, std::string Password, int permissions
                )   : clsPerson(Fullname,  Email, PhoneNbr)
    {

            _MODE = MODE;
            _Username = Username;
            _Password = Password;
            _permissions = permissions;
    }



    void    SetUsername(std::string Username)
    {
        this->_Username = Username;
    }


    void    SetPassword(std::string Password)
    {
        this->_Password = Password;
    }


    void    SetPermissons(int permissions)
    {
        this->_permissions = permissions;
    }


    void    SetMode(E_MODE MODE)
    {
        this->_MODE = MODE;
    }




    std::string    Username()
    {
        return (_Username);
    }


    std::string    Password()
    {
        return (_Password);
    }


    int    Permissions()
    {
        return (_permissions);
    }



    bool isUserExist()
    {
        return (!_isEmpty());
    }


    static bool isUserExist(std::string Username)
    {
        clsBankUser User = Find(Username);

        return (User.isUserExist());
    }

    static clsBankUser	Find(std::string Username)
    {
        std::fstream		FileSystem;
        std::string						RecordLine;
        std::string _Filename = "Data/Users.txt";

        FileSystem.open(_Filename,	std::ios::in);
        // FileSystem.open("E:/Work/01_Programming_MOC/01_Programming-Advices-Training-Program/Programming Foundations and Algorithms (Courses 01-13)/09__OOP_Applications/05_LogicLayer/Data/Users.txt", std::ios::in);

        if (FileSystem.is_open())
        {
            while (getline(FileSystem, RecordLine))
            {
                clsBankUser	BankUserTmp = _ConvertLineIntoUser(RecordLine);

                if (BankUserTmp.Username() == Username)
                {
                    FileSystem.close();
                    return (BankUserTmp);
                }
            }
            
            FileSystem.close();
        }
        else
        {	std::cerr << "Error opening file";
            exit(1);
        }
        return (_rtrnEmptyUserObject());
    }


    static clsBankUser	Find(std::string Username, std::string Password)
    {
        std::fstream		FileSystem;
        std::string						RecordLine;
        std::string _Filename = "Data/Users.txt";

        FileSystem.open(_Filename,	std::ios::in);
        // FileSystem.open("E:/Work/01_Programming_MOC/01_Programming-Advices-Training-Program/Programming Foundations and Algorithms (Courses 01-13)/09__OOP_Applications/05_LogicLayer/Data/Users.txt", std::ios::in);

        if (FileSystem.is_open())
        {
            while (getline(FileSystem, RecordLine))
            {
                clsBankUser	BankUserTmp = _ConvertLineIntoUser(RecordLine);

                if ((BankUserTmp.Username() == Username) && (BankUserTmp.Password() == Password))
                {
                    FileSystem.close();
                    return (BankUserTmp);
                }
            }
            
            FileSystem.close();
        }
        else
        {	std::cerr << "Error opening file";
            exit(1);
        }
        return (_rtrnEmptyUserObject());
    }

    static clsBankUser	AddNewBankUser(std::string Username)
    {
        return (clsBankUser(E_MODE::ADD_MODE, "" , "", "", "", Username, "", 0));
    }


    static std::vector <clsBankUser> GetBankUsersListToVect()
    {
        return (_LoadUsersFromFile());
    }


    short	DeleteBankUserThenSave()
    {
        std::vector <clsBankUser> BankUsersVec;
        std::vector <clsBankUser>::iterator IterVec;

        BankUsersVec = _LoadUsersFromFile();
        IterVec = BankUsersVec.begin();

        while (IterVec != BankUsersVec.end())
        {
            if (this->Username() == IterVec->Username())
                IterVec = BankUsersVec.erase(IterVec);		//		 Erase returns the next valid iterator)
            else
                ++IterVec;
        }
        if (!(_SaveUsersObjsToFile(BankUsersVec)))
        {
            *this = _rtrnEmptyUserObject();
            return (0); 				    //Succeed in Saving.	 :)
        }
        return (-1);		//	BankUser isn't Deleted (Failed)
    }

    enum class en_SaveResults
    {
        SV_SUCCEEDED,
        SV_FAILED_EMPTY_OBJ,
        SV_FAILED_UPDATING,
        SV_FAILED_EXIST_ACCNT_NBR,
        AS_NULL
    };

    
    en_SaveResults	Save()
    {
        if (_isEmpty())		//Empty Mode
            return (en_SaveResults::SV_FAILED_EMPTY_OBJ);
        else if ((_MODE == E_MODE::UPDATE_MODE) && isUserExist(this->Username()))
        {
            if (!_Update())
                return (en_SaveResults::SV_SUCCEEDED);
            else
                return (en_SaveResults::SV_FAILED_UPDATING);
        }
        else if ((_MODE == E_MODE::ADD_MODE))
        {
            if (isUserExist(this->Username()))
                return (en_SaveResults::SV_FAILED_EXIST_ACCNT_NBR);
            if (!(_AddNewUser()))
            {
                _MODE = E_MODE::UPDATE_MODE;
                return (en_SaveResults::SV_SUCCEEDED);
            }
        }
        
        return (en_SaveResults::AS_NULL);
    }	








    enum E_USERS_PERMISSIONS
    {
        PER_ALL = -1,   PER_LIST_CLIENTS = 1,   PER_ADD_NEW_CLIENTS = 2, PER_DELETE_CLIENTS = 4, 
        PER_UPDATE_CLIENTS = 8, PER_FIND_CLIENTS = 16, PER_MANAGE_TRANSACTIONS = 32, PER_MANAGE_USERS = 64,
        PER_SHOW_LOGIN_REG_HISTORY = 128 
    };





    short   CheckAccessPermission(E_USERS_PERMISSIONS PERMISSION)
    {
        if (this->Permissions() == E_USERS_PERMISSIONS::PER_ALL)
            return (0);                 // Successfully Having Access Permission.
        if ((this->Permissions() & PERMISSION) == PERMISSION) 
            return (0);                 // Successfully Having Access Permission.

        return (1);                 // FAILED !! DON't Having Access Permission.
    }


    short   RegisterLogin()
    {
        std::string RegisterLoginLine = _ConvertLoginRecToRegisterLine();

        if (!_AppendLoginRecordIntoRegisterFile(RegisterLoginLine))
            return 0;   //  Succeed

        return 1;       //Failed
    }


    static std::vector <s_LoginRegister>	GetLoginRegRecordsList()
    {
        return (_LoadLoginRegRecordsFromFile());
    }






};




    



#endif