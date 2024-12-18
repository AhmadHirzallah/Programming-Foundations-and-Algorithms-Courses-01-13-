#pragma once

#ifndef	CLSFINDCLIENTSCREEN_HPP
# define	CLSFINDCLIENTSCREEN_HPP


// # include "../../Include/"
# include "../../Core/clsBankClient.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../clsScreen.hpp"
# include "clsShowClientsScreen.hpp"
# include "../clsClientScreen.hpp"
# include "iomanip"





class	clsFindClientScreen : protected clsClientScreen
{
	
	public:
			static void	showFindClientScreen()
			{
				std::string	ID_ToFind = "";

				drawScreensHeaders("Find Client Screen");

				do
				{

					ID_ToFind = InputValidator::readString("\n\t\t\t\t\t\tPlease enter account ID number inorder to Find: ");
					if (!(clsBankClient::isClientExist(ID_ToFind)))
						printf("\n\t\t\t\t\t\tNo Client is Exist with this ID Number;\n");

				}					while (!(clsBankClient::isClientExist(ID_ToFind)));

				clsBankClient	Client = clsBankClient::Find(ID_ToFind);

				PrintClient(Client);
			}

	
};




# endif