#include <iostream>
#include "clsPerson.hpp"
#include "clsEmployee.hpp"

using namespace std;


int main (void)
{
    clsEmployee employee1;  //This inherits members from superclass

    employee1.set_firstname("Ahmad");
    employee1.set_lastname("Hirzallah");
    employee1.set_email("ahmad.omar@yahoo.com");
    employee1.set_phone_nbr("+972-23-2383-132");
    employee1.set_title("Software Engineer & Developer");
    employee1.set_department("IT Department");
    employee1.set_salary(2300.858);
    employee1.ft_print_person_info();
    employee1.ft_print_employee_info();
    employee1.ft_send_email("Hi pro", "How are you?");
    employee1.ft_send_sms("Please vote for Ahmad Hirzallah in Amman elections.\nThank you <3.");

    return (0);
}