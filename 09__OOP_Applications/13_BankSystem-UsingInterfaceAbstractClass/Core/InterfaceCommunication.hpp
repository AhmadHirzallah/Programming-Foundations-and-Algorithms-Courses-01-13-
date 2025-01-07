#pragma once

#ifndef INTERFACECOMMUNICATION_HPP	
# define	INTERFACECOMMUNICATION_HPP	

# include <iostream>
# include "../Include/CoreUtilities.hpp"
# include "../Include/InputValidator.hpp"
# include "../Include/StringUtils.hpp"


class InterfaceCommunication
{
private:

            /* data */
            ////////////

public:
        
            virtual void    SendEmail(std::string Title, std::string Body) = 0;
            virtual void    SendFax(std::string Title, std::string Body) = 0;
            virtual void    SendSMS(std::string Title, std::string Body) = 0;

};

#endif