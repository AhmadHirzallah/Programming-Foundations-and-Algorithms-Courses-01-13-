#pragma once

#ifndef	CLSSHOWCLIENTSSCREEN_HPP
# define	CLSSHOWCLIENTSSCREEN_HPP

// # include "../../Include/"
# include "../../Core/clsBankClient.hpp"
# include "../../Include/CoreUtilities.hpp"
# include "../../Include/InputValidator.hpp"
# include "../clsScreen.hpp"
# include "../clsClientScreen.hpp"
# include <iomanip>
# include <string>
# include <cstring>

class	clsShowClientsScreen : protected clsClientScreen
{

private:

			static void	_DisplayFormattedClients(std::vector <clsBankClient> &ClientsV)
			{
				const int SCREEN_WIDTH = 120; // Keep the screen width the same
				const int TABLE_WIDTH = 109;  // Adjusted table width after increasing balance size
				int PADDING = (SCREEN_WIDTH - TABLE_WIDTH) / 2 - 6; // Adjust padding for one more tab left

				// Print header
				printf("%s%*s____________________________________________________________________________________________________________________________________\n",
					CoreUtilities::Tabs(1).c_str(), PADDING + 2, "");
				printf("%s%*s| Client Number | Client Name              | Phone Number     | Email                             | Password        | Balance      |\n",
					CoreUtilities::Tabs(1).c_str(), PADDING, "");
				printf("%s%*s____________________________________________________________________________________________________________________________________\n",
					CoreUtilities::Tabs(1).c_str(), PADDING + 2, "");

				if (ClientsV.empty()) {
					printf("%s%*sNo Clients Available In the System!\n",
						CoreUtilities::Tabs(1).c_str(), PADDING, "");
				} else {
					// Iterate through clients and print each record
					for (clsBankClient &Client : ClientsV) {
						printf("%s%*s| %-12s | %-25s | %-16s | %-33s | %-15s | %-12.2f |\n",
							CoreUtilities::Tabs(1).c_str(), PADDING, "",
							Client.AccountID().c_str(),  // Client Number
							Client.Fullname().c_str(),   // Client Name
							Client.PhoneNbr().c_str(),   // Phone
							Client.Email().c_str(),      // Email (33 chars)
							Client.Password().c_str(),   // Password (15 chars)
							Client.balance());           // Balance (12 chars)
					}
				}

				// Print footer
				printf("%s%*s_____________________________________________________________________________________________________________________________________\n",
					CoreUtilities::Tabs(1).c_str(), PADDING + 2, "");
			}



public:

			static void	showAllClientsList()
			{
				std::vector <clsBankClient>	ClientV = clsBankClient::getClientsListV();
				std::string	SubTitle = "\t    -------(" + std::to_string(ClientV.size()) + ")-------";

				drawScreensHeaders("Clients List Screen", SubTitle);
				_DisplayFormattedClients(ClientV);
			}



};


#endif
