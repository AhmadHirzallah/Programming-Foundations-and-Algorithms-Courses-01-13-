#pragma once
#ifndef CLSPERSON_HPP
# define CLSPERSON_HPP

# include <iostream>

using namespace std;

class	clsPerson
{
    private:

                unsigned int                            _i_id;
                string          _firstname;
                string          _lastname;
                string          _fullname;
                string          _email;
                string          _phone_nbr;

    public:


            clsPerson()
            {   
            }

            clsPerson(unsigned int id, string firstname, string lastname, string email, string phone_nbr)
            {
                _i_id = id;
                _firstname = firstname;
                _lastname = lastname;
                _fullname = _firstname + " " + _lastname;
                _email = email;
                _phone_nbr = phone_nbr;
            }

            // Read Only ; get (return) ; but no set and change value; it is constant and unchangable
            unsigned int    id()
            {
                return (_i_id);
            }

            void    set_firstname(string new_firstname)
            {
                _firstname = new_firstname;
            }

            string    firstname()
            {
                return (_firstname);
            }

            void    set_lastname(string new_lastname)
            {
                _lastname = new_lastname;
            }

            string  lastname()
            {
                return (_lastname);
            }

            string  fullname()
            {
                _fullname = _firstname + " " + _lastname;
                return (_fullname);
            }

            void    set_email(string new_email)
            {
                _email = new_email;
            }

            string  email()
            {
                return (_email);
            }

            void    set_phone_nbr(string new_phone_nbr)
            {
                _phone_nbr = new_phone_nbr;
            }

            string  phone_nbr()
            {
                return (_phone_nbr);
            }

            void    ft_print_person_info()
            {
                printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
                printf("Info:\n");
                printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
                printf("ID: %u\n", _i_id);
                printf("First Name: %s\n", _firstname.c_str());
                printf("Last Name: %s\n", _lastname.c_str());
                printf("Full Name: %s\n", fullname().c_str());
                printf("Email: %s\n", _email.c_str());
                printf("Phone Number: %s\n", _phone_nbr.c_str());
            }

            void    ft_send_email(string subject, string body_of_email)
            {
                printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
                printf("\nThe email is sent to (%s) email Successfully\n\n", _email.c_str());
                printf("Email Info:\n\nSubject: \"%s\"\n\n", subject.c_str());
                printf("Body: \"%s\"\n\n\n", body_of_email.c_str());
            }

            void    ft_send_sms(string sms_message)
            {
                printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
                printf("\nThe SMS Message is sent to (%s) phone number Successfully\n\n\n", _phone_nbr.c_str());
                printf("SMS message: \"%s\"\n\n", sms_message.c_str());
            }
};

#endif