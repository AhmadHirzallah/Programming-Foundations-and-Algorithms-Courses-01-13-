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
                printf("Info (Personal):\n");
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



class   cls_employee : public cls_person // this means that there is subclass/derived called employee that inherits the person super/base class 
{
    // employee class inherits from person class
    private:

                string  _title;
                string  _department;
                double  _salary;

    public:


                cls_employee(unsigned int id, string firstname, string lastname,string email, string phone_nbr,
                 string title, string department, double salary) :cls_person(id, firstname, lastname, email, phone_nbr)
                {
                    _title = title;
                    _department = department;
                    _salary = salary;
                }


                void	set_title(string new_title)
				{
					_title = new_title;
				}

				string	title()
				{
					return (_title);
				}

                void	set_salary(double salary)
				{
					_salary = salary;
				}

				double	salary()
				{
					return (_salary);
				}

                void	set_department(string department)
				{
					_department = department;
				}

				string	department()
				{
					return (_department);
				}

                void	ft_print_employee_info()
				{
                    ft_print_person_info();
                    printf("_________\n\nEmployee Info\n");
                    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
					printf("Title: %s\n", title().c_str());
					printf("Department: %s\n", department().c_str());
					printf("Salary: %.2f\n", salary());
					printf("\n");
				}
};


int main (void)
{
    cls_employee    employee1(23, "Ahmad", "Hirzallah", "Ahmad.hirzallah@gmail.com", "07983178312",
                                 "Software Engineer & Developer", "IT Department", 2700.859);  //This inherits members from superclass/baseclass


    employee1.ft_print_employee_info();
    employee1.ft_send_email("Hi pro", "How are you?");
    employee1.ft_send_sms("Please vote for Ahmad Hirzallah in Amman elections.\nThank you <3.");

    return (0);
}