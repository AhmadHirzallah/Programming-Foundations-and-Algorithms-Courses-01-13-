
#pragma once

#ifndef	CLSDELETECLIENTSCREEN_HPP
# define	CLSDELETECLIENTSCREEN_HPP


// # include "../../Include/"
# include "../../Core/clsBankClient.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../clsScreen.hpp"
# include "clsShowClientsScreen.hpp"
# include "../clsClientScreen.hpp"
# include "iomanip"





class	clsDeleteClientScreen: protected clsClientScreen
{

private:




public:

			static void	ShowDeleteClientScreen()
			{
				std::string	ID_ToDelete = "";
				char	delete_approve = 'N';

				drawScreensHeaders("Delete a Client Screen");
				
				do
				{

					ID_ToDelete = InputValidator::readString("\n\t\t\t\t\t\tPlease enter account ID number inorder to Delete: ");
					if (!(clsBankClient::isClientExist(ID_ToDelete)))
						printf("\nNo Client is Exist with this ID Number;\n");

				}					while (!(clsBankClient::isClientExist(ID_ToDelete)));
				

				clsBankClient	ClientToDelete = clsBankClient::Find(ID_ToDelete);
				PrintClient(ClientToDelete);
				delete_approve = InputValidator::readChr("\n\n\t\t\t\t\tAre you sure do you want to delete the Client? (Y/N): ");
				if (std::toupper(delete_approve) != 'Y')
					return ;
				
				if(ClientToDelete.deleteClientObj())
				{
					std::cout << "\nClient is Deleted Succesfully.";
					PrintClient(ClientToDelete);
				}
				else
					std::cout << "\nClient isn't Deleted.";

			}

	
};




# endif