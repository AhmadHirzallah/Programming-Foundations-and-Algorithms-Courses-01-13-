#pragma once

#ifndef	CLSSCREEN_HPP
# define	CLSSCREEN_HPP

# include "../Include/CoreUtilities.hpp"
# include "../Include/DateUtils.hpp"
# include "../Include/InputValidator.hpp"
# include "../Include/StringUtils.hpp"

# include <iostream>

# include "../Include/Global.hpp"

class	clsScreen
{


private:


		static void	_ShowAccessDenied()
		{
			std::cout << CoreUtilities::Tabs(7) << std::setw(40) << "=======================================" << std::endl;
			std::cout << CoreUtilities::Tabs(7) << std::setw(40) << "|         Access Denied!             |" << std::endl;
			std::cout << CoreUtilities::Tabs(7) << std::setw(40) << "|    Contact your Administrator.     |" << std::endl;
			std::cout << CoreUtilities::Tabs(7) << std::setw(40) << "=======================================" << std::endl;
		}




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





			static short	CheckScreenAccessRights(clsBankUser::E_USERS_PERMISSIONS PERMISSION)
			{
				if (!(g_ActiveUser.CheckAccessPermission(PERMISSION)))
					return (0);			//	Successfully having Permission.
				else
					_ShowAccessDenied();

				return(1);
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