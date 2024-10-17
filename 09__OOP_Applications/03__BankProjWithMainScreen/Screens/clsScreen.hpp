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
				int width = 60;  // Total width for the header and decorative borders
				int padding = (width - Title.length()) / 2;  // Padding for centering the title

				std::cout << CoreUtilities::Tabs(5) << "\n\n\t" << CoreUtilities::Tabs(5) << std::setfill('*') << std::setw(width) << "" << std::setfill(' ') << std::endl;
				std::cout << CoreUtilities::Tabs(5) << "\t*" << std::setw(width - 2) << " " << "*" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << "\t*" << std::setw(padding) << " " << Title << std::setw(padding - 1) << " " << "*" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << "\t*" << std::setw(width - 2) << " " << "*" << std::endl;
				std::cout << CoreUtilities::Tabs(5) << "\t" << std::setfill('*') << std::setw(width) << "" << std::setfill(' ') << std::endl;
				std::cout << CoreUtilities::Tabs(5) <<"\t" << std::setfill('~') << std::setw(width) << "" << std::setfill(' ') << std::endl;

			}
};



#endif