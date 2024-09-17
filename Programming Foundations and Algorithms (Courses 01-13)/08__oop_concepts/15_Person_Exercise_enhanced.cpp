#include <iostream>

using namespace std;

class   cls_person
{
    private:

                unsigned int                            _i_id;
                string          _firstname;
                string          _lastname;
                string          _fullname;
                string          _email;
                string          _phone_nbr;

    public:

            cls_person(unsigned int id, string firstname, string lastname, string email, string phone_nbr)
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
                printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
                printf("\n");
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

int main (void)
{
    cls_person  person1(1, "Ali", "Mahmoud", "alimahmoud@gmail.com", "+972-223-31-1324");

    person1.ft_print_person_info();
    person1.ft_send_email("Boss; I want an increase in my salary", "Hello Boss,\nI am Ali Mahmoud, I am sending to you because i have increase in my performance and i am doing too good job so i would like to suggest if you can give me increase in my salary, \nThanks\nAli Mahmoud.");
    person1.ft_send_sms("Please vote for Sameer Mahmoud in Amman elections.\nThank you <3 .");
    return (0);
}