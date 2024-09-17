#include <iostream>

using namespace std;

class cls_employee
{
    private:

				unsigned int	_id;
				double					_salary;
				string					_department;
				string					_firstname;
				string					_lastname;
				string					_fullname;
				string					_title;
				string					_email;
				string					_phone_nbr;
	
	public:

				cls_employee(unsigned int id, string firstname,
								string lastname, string title,
								string email, string phone_nbr, 
								double salary , string department)
				{
					_id = id;
					_firstname = firstname;
					_lastname = lastname;
					_fullname = set_with_get_fullname();
					_title = title;
					_email = email;
					_phone_nbr = phone_nbr;
					_salary = salary;
					_department = department;
				}

				unsigned int	id()
				{
					return (_id);
				}

				void	set_firstname(string new_firstname)
				{
					_firstname = new_firstname;
				}

				string	firstname()
				{
					return (_firstname);
				}

				void	set_lastname(string new_lastname)
				{
					_lastname = new_lastname;
				}

				string	lastname()
				{
					return (_lastname);
				}

				string	set_with_get_fullname()
				{
					_fullname = _firstname + " " + _lastname; 
					return (_fullname);
				}			

				void	set_title(string new_title)
				{
					_title = new_title;
				}

				string	title()
				{
					return (_title);
				}

				void	set_email(string new_email)
				{
					_email = new_email;
				}

				string	email()
				{
					return (_email);
				}

				void	set_phone_nbr(string new_phone_nbr)
				{
					_phone_nbr = new_phone_nbr;
				}

				string	phone_nbr()
				{
					return (_phone_nbr);
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
					printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
					printf("Info:\n");
					printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
					printf("ID: %i\n", id());
					printf("First Name: %s\n", firstname().c_str());
					printf("Last Name: %s\n", lastname().c_str());
					printf("Full Name: %s\n", set_with_get_fullname().c_str());
					printf("Title: %s\n", title().c_str());
					printf("Email: %s\n", email().c_str());
					printf("Phone Number: %s\n", phone_nbr().c_str());
					printf("Salary: %.2f\n", salary());
					printf("Department: %s\n", department().c_str());
					printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
					printf("\n");
				}

				void    ft_send_email(string subject, string body_of_email)
				{
					printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
					printf("\nThe email is sent to (%s) email Successfully\n", email().c_str());
					printf("Email Info:\n\nSubject: \"%s\"\n\n", subject.c_str());
					printf("Body: \"%s\"\n\n\n", body_of_email.c_str());
				}

				void    ft_send_sms(string sms_message)
				{
					printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
					printf("\nThe SMS Message is sent to (%s) phone number Successfully\n\n\n", phone_nbr().c_str());
					printf("SMS message: \"%s\"\n\n", sms_message.c_str());
				}

};

int main (void)
{
    cls_employee  employee1_obj(19, "Ahmad", "Hirzallah", "Software Engineer & Developer",
								 "ahmadhirza@gmail.com", "0792002831", 2300.9688, "IT Department");

    employee1_obj.ft_print_employee_info();
    employee1_obj.ft_send_email("Boss; I want an increase in my salary", "Hello Boss,\nI am Ahmad Omar, I am sending to you because i have increase in my performance and i am doing too good job so i would like to suggest if you can give me increase in my salary, \nThanks\nAhmad Hirzallah.");
    employee1_obj.ft_send_sms("Please vote for Ahmad Hirzallah in Amman elections.\nThank you <3.");
    return (0);
}