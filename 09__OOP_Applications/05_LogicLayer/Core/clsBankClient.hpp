#ifndef	CLSBANKCLIENT_HPP
# define	CLSBANKCLIENT_HPP

# include <iostream>
# include "../Include/CoreUtilities.hpp"
# include "../Include/InputValidator.hpp"
# include "../Include/StringUtils.hpp"
# include "clsPerson.hpp"
# include <fstream>
# include <vector>
# include <string>
#include <pthread.h>


class	clsBankClient : public clsPerson
{




public:

			enum	e_mode { EMPTY_MODE = 0, UPDATE_MODE = 1 };



			clsBankClient(e_mode mode, std::string Firstname, std::string Lastname, std::string Email, std::string PhoneNbr,
							 std::string AccountID, std::string Password, double balance)
						: clsPerson(Firstname, Lastname, Email, PhoneNbr)
			{
				_mode = mode;
				_AccountID = AccountID;
				_Password = Password;
				_balance = balance;
			}


			clsBankClient(e_mode mode, std::string fullname, std::string Email, std::string PhoneNbr,
							 std::string AccountID, std::string Password, double balance)
						: clsPerson(fullname, Email, PhoneNbr)
			{
				_mode = mode;
				_AccountID = AccountID;
				_Password = Password;
				_balance = balance;
			}


			bool	isEmpty()
			{
				return (Mode() == e_mode::EMPTY_MODE);
			}


			void	setPassword(std::string Password)
			{
				this->_Password = Password;
			}


			void	setBalance(double balance)
			{
				this->_balance = balance;
			}


			double	balance()
			{
				return (_balance);
			}


			std::string	Password()
			{
				return (_Password);
			}


			//			Read Only : Can write or change it :)
			std::string	AccountID() 
			{
				return (_AccountID);
			}

			
			e_mode	Mode()
			{
				return (_mode);
			}

/*
			void	Print()
			{
				std::cout << "\n~~~~~~~~~~~~~~~~~~~";
				std::cout << "\nClient Card:";
				std::cout << "\n___________________";
				std::cout << "\nFirstName   : " << Firstname();
				std::cout << "\nLastName    : " << Lastname();
				std::cout << "\nFull Name   : " << Fullname();
				std::cout << "\nEmail       : " << Email();
				std::cout << "\nPhone       : " << PhoneNbr();
				std::cout << "\nAcc. Number : " << AccountID();
				std::cout << "\nPassword    : " << Password();
				std::cout << "\nBalance     : " << balance();
				std::cout << "\n___________________\n";
			}
*/


		//	Bank System Functionallities :::: 



/*
When you specify the path "Data/Clients.txt", it is a relative path that is relative to the current working directory (CWD), which is typically the directory from which the program is being run.
Since your program is likely being run from the root of the project folder (where main.cpp is located), the relative path Data/Clients.txt correctly points to the file in the Data folder.
Key Point:
The CWD is determined by where the program is run from, not by the location of the source code file (like main.cpp).
Therefore, if you are running the program from the directory where main.cpp resides, the relative path "Data/Clients.txt" will correctly point to the file.
*/
			static clsBankClient	Find(std::string ID)
			{
				std::fstream		FileSystem;
				std::string						RecordLine;

				FileSystem.open("Data/Clients.txt",	std::ios::in);
				// FileSystem.open("E:/Work/01_Programming_MOC/01_Programming-Advices-Training-Program/Programming Foundations and Algorithms (Courses 01-13)/09__OOP_Applications/05_LogicLayer/Data/Clients.txt", std::ios::in);

				if (FileSystem.is_open())
				{
					while (getline(FileSystem, RecordLine))
					{
						clsBankClient	ClientTmp = _ConvertLineIntoClientObj(RecordLine);

						if (ClientTmp.AccountID() == ID)
						{
							FileSystem.close();

							return (ClientTmp);
						}
					}
					
					FileSystem.close();
				}
				else
				{	std::cerr << "Error opening file";
					exit(1);
				}
				return (_rtrnEmptyClientObject());
			}


			static clsBankClient	Find(std::string ID, std::string Password)
			{
				std::fstream		FileSystem;
				std::string						RecordLine;

				FileSystem.open("Data/Clients.txt",	std::ios::in);
				if (FileSystem.is_open())
				{
					while (getline(FileSystem, RecordLine))
					{
						clsBankClient	ClientTmp = _ConvertLineIntoClientObj(RecordLine);

						if ((ClientTmp.AccountID() == ID) && (ClientTmp.Password() == Password))
						{
							FileSystem.close();

							return (ClientTmp);
						}
					}
					
					FileSystem.close();
				}
				else
				{	std::cerr << "Error opening file";
					exit(1);
				}
				return (_rtrnEmptyClientObject());
			}


			static bool	isClientExist(std::string ID)
			{
				clsBankClient	Client = Find(ID);

				return (!(Client.isEmpty()));
				// return (Client.Mode() != e_mode::EMPTY_MODE);
			}



private:
			

			std::string	_AccountID;
			std::string	_Password;
			e_mode				 	_mode;
			double					_balance;

			

			static clsBankClient	_ConvertLineIntoClientObj(std::string FileRecodLine)
			{
				std::vector <std::string>	ClientDataSections;

				ClientDataSections = StringUtils::splitByDelim(FileRecodLine, "#//#", StringUtils::e_split_type::MULTI);

				return (clsBankClient(e_mode::UPDATE_MODE, ClientDataSections[0], ClientDataSections[1], ClientDataSections[2],
							ClientDataSections[3], ClientDataSections[4], ClientDataSections[5], (std::stod(ClientDataSections[6]))));
			}


			static clsBankClient	_rtrnEmptyClientObject()
			{
				return (clsBankClient(e_mode::EMPTY_MODE, "", "", "", "", "", "", 0));
			}
			


};

#endif