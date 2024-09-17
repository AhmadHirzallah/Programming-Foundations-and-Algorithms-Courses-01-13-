#include <iostream>

using namespace std;

struct s_person
{

};

class   cls_person
{
    private:
                int                                 _i_id;
                string      _str_firstname;
                string      _str_lastname;
                string      _str_fullname;
                string      _str_email;
                string      _str_phone_nbr;

                
    public:
                cls_person(int id, string firstname, string lastname, string email, string phone_nbr)
                {
                    _i_id = id;
                    _str_firstname = firstname;
                    _str_lastname = lastname;
                    _str_fullname = firstname + " " + lastname;
                    _str_email= email;
                    _str_phone_nbr = phone_nbr;
                }
                
                void    set_id(int id)
                {
                    _i_id = id;
                }

                int    get_id()
                {
                    return (_i_id);
                }

                void    set_str_firstname(string firstname)
                {
                    _str_firstname = firstname;
                }

                string    get_str_firstname()
                {
                    return (_str_firstname);
                }

                void    set_str_lastname (string lastname)
                {
                   _str_lastname = lastname;
                }

                string    get_str_lastname ()
                {
                    return (_str_lastname);
                }

                void    set_str_email(string email)
                {
                    _str_email = email;
                }

                string    get_str_email()
                {
                    return (_str_email);
                }

                void    set_str_phone_nbr(string phone_nbr)
                {
                  _str_phone_nbr = phone_nbr;
                }

                string    get_str_phone_nbr()
                {
                    return (_str_phone_nbr);
                }

                void    set_str_fullname ()
                {
                   _str_fullname = _str_firstname + " " + _str_lastname;
                }

                string    get_str_fullname()
                {
                    return (_str_fullname);
                }

                void    ft_print_info()
                {
                    printf("~~~~~~~~~~~~~~~~~~~~~~\nInfo\n\n~~~~~~~~~~~~~\n\n");
                    printf("ID\t\t: %i\n", _i_id);
                    printf("First Name\t: %s\n", _str_firstname.c_str());
                    printf("Last Name\t: %s\n", _str_lastname.c_str());
                    printf("Full Name\t: %s\n", _str_fullname.c_str());
                    printf("Email\t\t: %s\n", _str_email.c_str());
                    printf("Phone Number\t: %s\n", _str_phone_nbr.c_str());
                }

                void    ft_send_email(string subject, string body_of_email)
                {
                    printf("\n--------------\nThe following email is sent succesfully:\n\n");
                    printf("To email: %s\n", _str_email.c_str());
                    printf("Subject: %s\n", subject.c_str());
                    printf("Body:\n%s\n\n\n", body_of_email.c_str());
                }

                void    ft_send_sms(string message)
                {
                    printf("\n--------------\nThe following sms is sent succesfully:\n\n");
                    printf("To the phone number: %s\n", _str_phone_nbr.c_str());
                    printf("Message:\n%s\n\n\n", message.c_str());
                }

       
};

int main (void)
{
    cls_person person1(71, "Ahmad", "Hirzallah", "Ahmad.hirzalla.po@gmail.com", "0792191744");
    person1.ft_print_info();
    person1.ft_send_email("How is your day my brother?", "Hellow Ahmad,\nI don't hear you since a long time how are you?");
    person1.ft_send_sms("You got 100 GB;\nthey will be valid until 30/12/2024");
    return (0);
}