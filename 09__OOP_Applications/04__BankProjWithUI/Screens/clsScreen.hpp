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
				int totalWidth = 80;      // Total terminal width
				int contentWidth = 60;    // Width of the content within borders
				int padding = (totalWidth - contentWidth) / 2;

				// Print top border
				std::cout << CoreUtilities::Tabs(6) << std::setw(contentWidth) << "************************************************************" << std::endl;
				std::cout << CoreUtilities::Tabs(6) << std::setw(contentWidth) << "*                                                          *" << std::endl;

				// Print title, centered within content width
				int titlePadding = (contentWidth - Title.length()) / 2;
				std::cout << CoreUtilities::Tabs(6) << std::setw(titlePadding + Title.length()) << Title << std::endl;

				std::cout << CoreUtilities::Tabs(6) << std::setw(contentWidth) << "*                                                          *" << std::endl;
				std::cout << CoreUtilities::Tabs(6) << std::setw(contentWidth) << "************************************************************" << std::endl;
			}


};

#endif