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


//		******************** 	PRIVATE SECTION	*****************************
private:
			
			enum class	e_mode { EMPTY_MODE = 0, UPDATE_MODE = 1, ADD_NEW_CLIENT_MODE };



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
			

			bool	_isEmpty()
			{
				return (Mode() == e_mode::EMPTY_MODE);
			}


			static std::vector <clsBankClient>	_LoadClientsObjsFromFile()
			{
				std::vector <clsBankClient> ClientsVec;
				std::fstream							FileCtrl;
				std::string								FileDataLine;

				FileCtrl.open("Data/Clients.txt",	std::ios::in);
				if (FileCtrl.is_open())
				{
					while (getline(FileCtrl, FileDataLine))
					{
						clsBankClient	ClientObj = _ConvertLineIntoClientObj(FileDataLine);
						ClientsVec.push_back(ClientObj);
					}
					FileCtrl.close();
				}
				return (ClientsVec);
			}


			std::string	_ConvertClientObjIntoClientDataLine(clsBankClient &Client)
			{
				std::string ClientDataLine = Client.Firstname() + "#//#" + Client.Lastname() + "#//#" + Client.Email()
											 + "#//#" + Client.PhoneNbr() + "#//#" + Client.AccountID() + "#//#"
											 + Client.Password() + "#//#" + std::to_string(Client.balance());
				
				return (ClientDataLine);
			}

			//			Caused A problem When Adding Nexw Clent Into File ! 
			/*
			std::string	_ConvertClientObjIntoClientDataLine(std::string ID_Nbr) 	(You are searching for ID Nbr For Specific Client Before you add the lines into the file :)
			{
				clsBankClient Client = clsBankClient::Find(ID_Nbr);

				return (_ConvertClientObjIntoClientDataLine(Client));
			}
			*/	


			short	_SaveClientsObjsIntoFile(std::vector <clsBankClient>	&ClientsVec)
			{
				std::fstream	FileCtrl;
				std::string		FileDataLine;

				FileCtrl.open("Data/Clients.txt",	std::ios::out);
				if (FileCtrl.is_open())
				{
					for (clsBankClient &Client : ClientsVec)
					{
						FileDataLine = _ConvertClientObjIntoClientDataLine(Client);
						FileCtrl << FileDataLine << std::endl; 
					}
					FileCtrl.close();
					return (0);				//Succeed in Saving.	 :)
				}
				return (-1);					//Case of Error ::: Saving Failed. 		 :(


			}

			short	_Update()
			{
				std::vector <clsBankClient>	ClientsVec = _LoadClientsObjsFromFile();

				if (ClientsVec.size() > 0)
					for (clsBankClient &Client : ClientsVec)
					{
						if (Client.AccountID() == this->AccountID())
						{
							Client = *this;
							if (_SaveClientsObjsIntoFile(ClientsVec) == 0)
								return (0);
							else
								break;
						}
					}
					
				return (-1);	// Case of Error ::: Updating Failed
			}


			short _AppendAddingDataLineToFile(std::string DataLine)
			{
				std::fstream	FileSystem;

				FileSystem.open("Data/Clients.txt",	std::ios::app | std::ios::out );
				if (FileSystem.is_open())
				{
					FileSystem << DataLine << std::endl;
					FileSystem.close();
					return (0);
				}
				return (-1);		//Failed to add
			}


			short	_AddNewClient(std::string ClientID)
			{
				std::string DataLine;
				
				DataLine = _ConvertClientObjIntoClientDataLine(*this);
				if ((_AppendAddingDataLineToFile(DataLine)))
					return (-1); 								// Failed To ADD !!
				return (0);			//	Added Successfully
			}
			


//		******************** 	PUBLIC SECTION	*****************************
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


			clsBankClient(e_mode mode, std::string fullname, std::string Email, std::string PhoneNbr,
							 std::string AccountID, std::string Password, double balance)
						: clsPerson(fullname, Email, PhoneNbr)
			{
				_mode = mode;
				_AccountID = AccountID;
				_Password = Password;
				_balance = balance;
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

				return (!(Client._isEmpty()));
				// return (Client.Mode() != e_mode::EMPTY_MODE);
			}


			static clsBankClient	AddNewClient(std::string ID_Nbr)
			{
				return (clsBankClient(e_mode::ADD_NEW_CLIENT_MODE, "" , "", "", "", ID_Nbr, "", 0));
			}


			short	DeleteClient()
			{
				std::vector <clsBankClient> ClientsVec;
				std::vector <clsBankClient>::iterator IterVec;

				ClientsVec = _LoadClientsObjsFromFile();
				IterVec = ClientsVec.begin();

				while (IterVec != ClientsVec.end())
				{
					if (this->AccountID() == IterVec->AccountID())
						IterVec = ClientsVec.erase(IterVec);		//		 Erase returns the next valid iterator)
					else
						++IterVec;
				}
				if (!(_SaveClientsObjsIntoFile(ClientsVec)))
				{
					*this = _rtrnEmptyClientObject();
					return (0);
				}
				return (-1);		//	Client isn't Deleted
			}

			enum class en_SaveResults
			{
				SV_SUCCEEDED,
				SV_FAILED_EMPTY_OBJ,
				SV_FAILED_AFTER_EMPTY,
				SV_FAILED_EXIST_ACCNT_NBR,
				LIKE_NULL
			};


			static std::vector <clsBankClient> GetClientsListToVect()
			{
				return (_LoadClientsObjsFromFile());
			}
			
			en_SaveResults	Save()
			{
				if (_isEmpty())		//Empty Mode
					return (en_SaveResults::SV_FAILED_EMPTY_OBJ);
				else if ((_mode == e_mode::UPDATE_MODE) && isClientExist(this->AccountID()))
				{
					if (_Update() == 0)
						return (en_SaveResults::SV_SUCCEEDED);
					else
						return (en_SaveResults::SV_FAILED_AFTER_EMPTY);
				}
				else if ((_mode == e_mode::ADD_NEW_CLIENT_MODE))
				{
					if (isClientExist(this->AccountID()))
						return (en_SaveResults::SV_FAILED_EXIST_ACCNT_NBR);
					if (!(_AddNewClient(this->AccountID())))
					{
						_mode = e_mode::UPDATE_MODE;
						return (en_SaveResults::SV_SUCCEEDED);
					}
				}
				
				return (en_SaveResults::LIKE_NULL);
			}	

			
			static	double	CalculateTotalBalancesOfClients()
			{
				std::vector <clsBankClient> ClientsVec = GetClientsListToVect();
				double	balances_summation;

				balances_summation = 0;
				for (clsBankClient &Client : ClientsVec)
					balances_summation += Client.balance();
				
				return (balances_summation);
			}
			




};

#endif