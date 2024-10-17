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
			
			enum	e_mode { EMPTY_MODE = 0, UPDATE_MODE = 1, ADD_NEW_CLIENT_MODE };

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
			

			static std::vector <clsBankClient>	_LoadClientsFromFile(std::string FileName = "Clients.txt")
			{
				std::vector <clsBankClient>	Clients_V;
				std::string	Line;
				std::fstream	File;

				File.open(FileName, std::ios::in);
				
				if (!File.is_open())
				{
					std::cerr << "Error: Could not open file: " << FileName << std::endl;  // Add detailed error message
					
					return (Clients_V);  // Return an empty vector if the file cannot be opened
				}
				else if (File.is_open())
				{

					while (getline(File, Line))
					{
						clsBankClient Client = _ConvertLineIntoClientObj(Line);
						Clients_V.emplace_back(Client);
					}
					File.close();
				}
				return (Clients_V);
			}


			void	_AddNewClient()
			{
				_AddClientDataLineToFile(_ConverClientObjectToLine(*this));
			}


			static void	_AddClientDataLineToFile(std::string DataLine, std::string FileName = "Clients.txt")
			{
				std::fstream	File;

				File.open(FileName, std::ios::out | std::ios::app);

				if (File.is_open())
				{
					File << DataLine << std::endl;
					File.close();
				}
			}


			static std::string	_ConverClientObjectToLine(clsBankClient &Client, std::string Separator = "#//#")
			{
				std::string	ClientLineSet = "";

				ClientLineSet += Client.Firstname() + Separator;
				ClientLineSet += Client.Lastname() + Separator;
				ClientLineSet += Client.Email() + Separator;
				ClientLineSet += Client.PhoneNbr() + Separator;
				ClientLineSet += Client.AccountID() + Separator;
				ClientLineSet += Client.Password() + Separator;
				ClientLineSet += std::to_string(Client.balance());

				return (ClientLineSet);
			}


			void	_AddClientObjectToFile(clsBankClient &ClientObj)
			{
				_AddClientDataLineToFile((_ConverClientObjectToLine(*this)));
			}


			void	_SaveClientDataToFileOverwriting(std::vector <clsBankClient> Clients, std::string FileName = "Clients.txt")
			{
				std::fstream File;

				File.open(FileName, std::ios::out);

				if (File.is_open())
				{
					for (clsBankClient &ClientTmp : Clients)
						File << _ConverClientObjectToLine(ClientTmp) << std::endl;
				}
			}


			void	_Update()
			{
				std::vector <clsBankClient>	ClientsV = getClientsListV();
				
				for (clsBankClient &ClientTmp : ClientsV)
				{
					if (ClientTmp.AccountID() == this->AccountID())
					{
						ClientTmp = *this;
						break;
					}
				}
				_SaveClientDataToFileOverwriting(ClientsV);
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


			static std::vector <clsBankClient>	getClientsListV()
			{
				return (_LoadClientsFromFile());
			}


			static clsBankClient	addNewClientObj(std::string IDNbr)
			{
				return (clsBankClient(e_mode::ADD_NEW_CLIENT_MODE, "", "", "", "" , IDNbr, "", 0));
			}


			enum e_save_result
			{
				SV_FAIL_EMPTY_OBJ, SV_FAIL_ACCOUNT_NBR_USED,
				SV_SUCCEEDED, NULL_MODE
			};


			e_save_result	Save()
			{
				switch (_mode)
				{
					case e_mode::EMPTY_MODE :

						if (isEmpty())
							return (e_save_result::SV_FAIL_EMPTY_OBJ);
					
					case e_mode::UPDATE_MODE :
					
						_Update();
						return (e_save_result::SV_SUCCEEDED);
					


					case e_mode::ADD_NEW_CLIENT_MODE :

						if (isClientExist(AccountID()))
							return (e_save_result::SV_FAIL_ACCOUNT_NBR_USED);

						else
						{
							_AddNewClient();
							_mode = e_mode::UPDATE_MODE;

							return (e_save_result::SV_SUCCEEDED);
						}
						
					default:
							return (NULL_MODE);
				}
			}


				bool	deleteClientObj()
				{
					std::vector <clsBankClient>	Clients = _LoadClientsFromFile();

					for (auto it = Clients.begin(); it != Clients.end(); it++)
					{
						if (it->AccountID() == this->AccountID())
						{
							Clients.erase(it);
							_SaveClientDataToFileOverwriting(Clients);
							*this = _GetEmptyClientObject();
							return (true);
						}
					}
					return (false);
				}



};

#endif

/*


			// void	Print()
			// {
			// 	std::cout << "\n~~~~~~~~~~~~~~~~~~~";
			// 	std::cout << "\nClient Card:";
			// 	std::cout << "\n___________________";
			// 	std::cout << "\nFirstName   : " << Firstname();
			// 	std::cout << "\nLastName    : " << Lastname();
			// 	std::cout << "\nFull Name   : " << Fullname();
			// 	std::cout << "\nEmail       : " << Email();
			// 	std::cout << "\nPhone       : " << PhoneNbr();
			// 	std::cout << "\nAcc. Number : " << AccountID();
			// 	std::cout << "\nPassword    : " << Password();
			// 	std::cout << "\nBalance     : " << balance();
			// 	std::cout << "\n___________________\n";
			// }


*/