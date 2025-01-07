#pragma once

#ifndef	CLSPERSON_HPP
# define	CLSPERSON_HPP

# include <iostream>
# include "../Include/CoreUtilities.hpp"
# include "../Include/InputValidator.hpp"
# include "../Include/StringUtils.hpp"
# include "InterfaceCommunication.hpp"

class	clsPerson : public InterfaceCommunication
{

public:
			clsPerson(std::string Firstname, std::string Lastname, std::string Email, std::string PhoneNbr) 
			{
				_Firstname = Firstname;
				_Lastname = Lastname;
				_Fullname = Firstname + " " + Lastname;
				
				_Email = Email;
				_PhoneNbr = PhoneNbr;
			}


			clsPerson(std::string fullname ,std::string Email, std::string PhoneNbr) 
			{
				_Fullname = fullname;
				_Email = Email;
				_PhoneNbr = PhoneNbr;


				std::vector fullname_sections =  StringUtils::splitByDelim(fullname);
				_Firstname =  fullname_sections[0];
				_Lastname = fullname_sections[1];
			}

			void	setFirstname(std::string Firstname)
			{
				this->_Firstname = Firstname;
				_setFullname();
			}


			void	setLastname(std::string Lastname)
			{
				this->_Lastname = Lastname;
				_setFullname();
			}


			void	setEmail(std::string Email)
			{
				this->_Email = Email;
			}


			void	setPhoneNbr(std::string PhoneNbr)
			{
				this->_PhoneNbr = PhoneNbr;
			}


			std::string	Firstname()
			{
				return (_Firstname);
			}


			std::string	Lastname()
			{
				return (_Lastname);
			}


			std::string	Fullname()
			{
				return (_Fullname);
			}


			std::string	Email()
			{
				return (_Email);
			}


			std::string	PhoneNbr()
			{
				return (_PhoneNbr);
			}










		///// ******* 			ABSTRACT CLASS IMPLEMENTATION


            void    SendEmail(std::string Title, std::string Body)
			{
				printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
                printf("Email Info:\n\nSubject\"%s\"\n\n", Title.c_str());
                printf("Body: \"%s\"\n\n\n", Body.c_str());
			}

            void    SendFax(std::string Title, std::string Body)
			{
       			printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
                printf("Fax Info:\n\nSubject\"%s\"\n\n", Title.c_str());
                printf("Fax message: \"%s\"\n\n", Body.c_str());
			}


            void    SendSMS(std::string Title, std::string Body)
			{
       			printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
                printf("SMS Info:\n\nSubject\"%s\"\n\n", Title.c_str());
                printf("SMS message: \"%s\"\n\n", Body.c_str());
			}
			


private:

			std::string	_Firstname;
			std::string	_Lastname;
			std::string	_Fullname;
			std::string	_Email;
			std::string	_PhoneNbr;



			void	_setFullname()
			{
				_Fullname = _Firstname + " " + _Lastname;
			}
};


# endif