#pragma once

#ifndef	CLSSCREEN_HPP
# define	CLSSCREEN_HPP

// # include "../../Include/"
// # include ""
# include <iostream>

class	clsScreen
{

protected:

			static void	drawScreensHeaders(std::string Title, std::string SubTitle = "")
			{
				int width = 60; // Total width for the header and decorative borders
				int paddingTitle = (width - Title.length()) / 2;  // Centering the title
				int paddingSub = (width - SubTitle.length()) / 2; // Centering the subtitle

				// Top decorative border
				std::cout << CoreUtilities::Tabs(5) << "\n\n" 
						<< CoreUtilities::Tabs(6) << std::setfill('*') 
						<< std::setw(width) << "" << std::setfill(' ') << std::endl;

				// Blank line for spacing
				std::cout << CoreUtilities::Tabs(6) << "*" 
						<< std::setw(width - 2) << " " << "*" << std::endl;

				// Title centered
				std::cout << CoreUtilities::Tabs(6) << "*" 
						<< std::setw(paddingTitle) << " " << Title 
						<< std::setw(paddingTitle - 2) << " " << "*" << std::endl;

				// Subtitle centered, only if SubTitle is not empty
				if (!SubTitle.empty())
				{
					std::cout << CoreUtilities::Tabs(5) << "\t*" 
							<< std::setw(paddingSub) << " " << SubTitle 
							<< std::setw(paddingSub - 2) << " " << "*" << std::endl;
				}

				// Blank line for spacing
				std::cout << CoreUtilities::Tabs(5) << "\t*" 
						<< std::setw(width - 2) << " " << "*" << std::endl;

				// Bottom decorative borders
				std::cout << CoreUtilities::Tabs(5) << "\t" 
						<< std::setfill('*') << std::setw(width) << "" << std::setfill(' ') << std::endl;
				std::cout << CoreUtilities::Tabs(5) << "\t" 
						<< std::setfill('~') << std::setw(width) << "" << std::setfill(' ') << std::endl;
			}

			//				Used in: clsAddNewClient
			static short   inputReadingClientInfo(clsBankClient &Client)
			{
				char    proceed_fl = 'n';

				std::cout <<"\n\nPlease if you want to continue enter (y):  ";
				std::cin >> proceed_fl;
				if (tolower(proceed_fl) != 'y')
					return (1);                     //      Stop Input return

				// std::string SubHeader = "Client With ID Number:" + Client.AccountID();
				// clsMainScreen::drawScreensHeaders("Updating Client Information Screen", SubHeader);
				Client.setFirstname(InputValidator::readString("\n\nPlease enter First Name: "));
				Client.setLastname(InputValidator::readString("Please enter Last Name: "));
				Client.setEmail(InputValidator::readString("Please enter Email: "));
				Client.setPhoneNbr(InputValidator::readString("Please enter Phone Number: "));
				Client.setPassword(InputValidator::readString("Please enter Password: "));
				Client.setBalance(InputValidator::readRangedNumberDouble(0, std::numeric_limits<double>::max(), "Please enter the Balance: "));
				return (0);
			}


			// Used For : 
			static void    printClientInfoCard(clsBankClient &Client)
			{
				int cardWidth = 45;  // Width of the card block
				int totalWidth = 160; // Total terminal width
				int padding = (totalWidth - cardWidth) / 2;  // Padding for centering the card block

				std::cout << "\n\n";
				std::cout << std::setw(padding) << std::right << "" << "Client Card:" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "First Name   : " << Client.Firstname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Last Name    : " << Client.Lastname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Full Name    : " << Client.Fullname() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Email        : " << Client.Email() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Phone        : " << Client.PhoneNbr() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Acc. Number  : " << Client.AccountID() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Password     : " << Client.Password() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "Balance      : " << std::fixed << std::setprecision(5) 
						<< Client.balance() << std::endl;
				std::cout << std::setw(padding) << std::right << "" << "___________________________" << std::endl;
				std::cout << std::endl;
			}





};



#endif



			/*
				static void	drawScreensHeaders(std::string Title, std::string SubTitle = "")
				{
					int width = 60;  // Total width for the header and decorative borders
					int padding = (width - Title.length()) / 2;  // Padding for centering the title

					std::cout << CoreUtilities::Tabs(5) << "\n\n\t" << CoreUtilities::Tabs(5) << std::setfill('*') << std::setw(width) << "" << std::setfill(' ') << std::endl;
					std::cout << CoreUtilities::Tabs(5) << "\t*" << std::setw(width - 2) << " " << "*" << std::endl;
					std::cout << CoreUtilities::Tabs(5) << "\t*" << std::setw(padding) << " " << Title << std::setw(padding - 1) << " " << "*" << std::endl;
					std::cout << CoreUtilities::Tabs(5) << "\t*" << std::setw(width - 2) << " " << "*" << std::endl;
					std::cout << CoreUtilities::Tabs(5) << "\t" << std::setfill('*') << std::setw(width) << "" << std::setfill(' ') << std::endl;
					std::cout << CoreUtilities::Tabs(5) <<"\t" << std::setfill('~') << std::setw(width) << "" << std::setfill(' ') << std::endl;

				}
			*/