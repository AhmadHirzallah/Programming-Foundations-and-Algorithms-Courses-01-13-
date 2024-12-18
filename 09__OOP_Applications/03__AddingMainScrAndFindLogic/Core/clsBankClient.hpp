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


class	clsBankClient : public clsPerson
{


private:
			
			enum	e_mode { EMPTY_MODE = 0, UPDATE_MODE = 1 };

			e_mode				 	_mode;
			double					_balance;
			std::string	_AccountID;
			std::string	_Password;

			

			static clsBankClient	_ConvertLineIntoClientObj(std::string FileRecodLine)
			{
				std::vector <std::string>	ClientDataSections;

				ClientDataSections = StringUtils::splitByDelim(FileRecodLine, "#//#", StringUtils::e_split_type::MULTI);

				return (clsBankClient(e_mode::UPDATE_MODE, ClientDataSections[0], ClientDataSections[1], ClientDataSections[2],
							ClientDataSections[3], ClientDataSections[4], ClientDataSections[5], (std::stod(ClientDataSections[6]))));
			}



			static clsBankClient	_GetEmptyClientObject()
			{
				return (clsBankClient(e_mode::EMPTY_MODE, "", "", "", "", "", "", 0));
			}
			


public:

			clsBankClient(e_mode mode, std::string Firstname, std::string Lastname, std::string Email, std::string PhoneNbr,
							 std::string AccountID, std::string Password, double balance)
						: clsPerson(Firstname, Lastname, Email, PhoneNbr)
			{
				_mode = mode;
				_AccountID = AccountID;
				_Password = Password;
				_balance = balance;
			}


			clsBankClient(e_mode mode,  std::string fullname, std::string Email, std::string PhoneNbr,
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
				return (_mode == e_mode::EMPTY_MODE);
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


			std::string	AccountID()
			{
				return (_AccountID);
			}

			
			e_mode	Mode()
			{
				return (_mode);
			}


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



			static clsBankClient	Find(std::string ID)
			{
				std::fstream		FileSystem;
				std::string						RecordLine;

				FileSystem.open("Clients.txt",	std::ios::in);
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

				return (_GetEmptyClientObject());
			}


			static clsBankClient	Find(std::string ID, std::string Password)
			{
				std::fstream		FileSystem;
				std::string						RecordLine;

				FileSystem.open("Clients.txt",	std::ios::in);
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

				return (_GetEmptyClientObject());
			}


			static bool	isClientExist(std::string ID)
			{
				clsBankClient	Client = Find(ID);

				return (!(Client.isEmpty()));
				// return (Client.Mode() != e_mode::EMPTY_MODE);
			}


};

#endif